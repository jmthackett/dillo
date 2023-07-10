dpi1-v1.0 (draft 10, with implementation)
by: Jorge Arellano, Eric GaudetJul 26, 2003

> This document came from https://www.dillo.org/dpi1.html which as of 10/07/2023 was in bad shape: displayed in a preformatted text blob with no newlines. I've converted the below to markdown by hand. A few editorial notes are included in places where I've not been completely sure what I'm looking at, or had a thought about the contents of the document.
> My impression is that this is a reasonably good description of what is there in the code today, and a few bits that hadn't been implemented at the time have been added since it was written. I have marked where these are, to the best of my knowledge.
> -jmthackett

*This document is an hybrid between a draft and a doc. This is because the full dpi1 spec isn't completely finished yet, but we already have a working framework to develop with.*

# Simple plugins (dpi1)

# Introduction 

Hopefully, dillo will have two types of plugins: one of asimple nature (described in this document), that operates in asimilar way of CGIs (with some extensions), and another that integrates interaction with the rendering engine and its widgets. The fact is that our current rendering system, and its associated internal layers are still under construction, makes it almost impossible to begin working on dpi2, and on the otherhand, gives an excellent oportunity to focus on dpi1 (that's also expected to be easier to program with). 

We expect dpi1 to be incrementally extensible, but also very simple in its concept at the same time. 

Please bear the simplicity concept in mind while studying this document. That's the basis for a powerful and clean dpi spec.

# Motivation 

Dillo aims to be a small, fast and efficient web browser. This kind of PI is designed to push out of the main code features that usually are optional, and also some others that are required (bookmarks for instance).

The design idea is to keep the main code-base small and to simplify the development of new features, by not requiring a plugin programmer to know the whole internals of dillo. This way, extensions can be easily coded, and there's also place for developing unrelated programs that can use dillo as a GUI! 

# Overview

Technically, the plugin program is a coprocess (an independent program spawned by the browser) that communicates with the browser through a certain channel. The current implementation uses unix domain sockets: 

```
---------------------->  ------  | Browser |   | socket |   | PI |  ---------  <-------------------
```
> Note while editing: it isn't clear to me what this was meant to look at. I am guessing.

Note: actually, there's a daemon manager process involved inthe communication between dillo and its PIs. It is documented in "devdoc/Dpid.md", but in the end, things work as the above diagram shows. PI developers should read both this spec and Dpid.md.

The main idea is to have a bidirectional channel on which the browser and the plugin can communicate. The data flow is encapsulated in a small but flexible protocol (dpi protocol) that resembles HTML tags. 

For instance, for sending an status message from the plugin to the browser: 

```
<dpi cmd='send_status_message' msg='Hello browser!'>
```

Note that with this scheme: 

* PI-programs can be one-demand/one-response, and there's space for multiple negotiations between the browser and the plugin too.
* Status/progress messages can be passed back to the browser.
* Browser and plugin can request information from each other, and they can also set data!
* It is possible to handle persistent dpi1 processes, though not a requirement.
* It's easy to extend the protocol by adding new operations without affecting backward compatibility.
* There's plenty of choice for PI languages.
* Plugin programs are managed with an intermediate daemon. This makes possible having several dillo instances using the same plugin.

# How does it work?

In general terms, the browser starts (or contacts) the PI whenit finds something that belongs to it (as an URI), and hands it to the PI. The PI receives the request, processes it and answers back in the form of an HTML page, or status message, or a dpicommand. A simple session (one-demand/one-response) can look like this: 

* The browser finds an URI that belongs to a certain PI.
* The browser prepares to send the URI to the PI. 
* The PI starts.
* The browser handles the URI to the PI with a dpi command.
* The PI makes/composes its answer (an HTML page) and sends it back within dpi protocol datagrams.
* The PI acknowledges the browser when done, and optionally exits.

# Some examples

Before getting into the protocol itself, it may be ilustrativeto look at some functionality that could be handled using PIs. For those willing to participate in the protocol developing process, it's certainly advised to keep these examples in mind for testing design ideas. 

1) Downloads
 * current cache allocates them in memory, so handing them to an external program (PI) has several advantages.
 * the PI chooses which agent (wget, curl, ...) to use, and sends feedback to dillo's download interface (HTML).
 * Downloads don't stop if dillo crashes.

2) FTP
* to browse FTP directories (PI outputs HTML). 
* Downloads using 1). 
* progress messages (as logging in, etc) can go to the status bar.
3) Bookmarks
* The BM PI maintains the BM database (a single file!).
* The PI builds an HTML page for dillo.
* Needs communication with the browser (URI, titles, add bookmark, etc).
* Some of the functions can be handled with FORMS.
* Browser may clean BM-pages out of the stack, for them not to show in history.
* Exporting BM becomes a matter of Save-page-as!

*NOTE: All of this has been already implemented (BM).*

4) Preferences (AKA configuration) 
* PI requests information from the browser (current prefs).
* PI commands the browser to change its "state"
* PI maintains dillorc 
* As 3), may require stack-cleaning of page.
5) Info reader. 
* Just a handy info to html filter (very simple). 
* one-demand/one-response.
6) Doc viewer (?)
* uses an external program to convert doc to html
7) Help browser 
* A PI that knows of local documentation, presents an index and probably a search feature!
8) A handler PI for "mailto:"

(...)

Well, that's the idea of simple PI. A way of extending dillo to suit end-user needs, without requiring extensive knowledge of its internals. Note also that these extensions don't make into the core of the browser.

# Developing a dillo plugin

I think the best way to get started will be to explain the basics of "dillo <=> PI" communication, then review the already implemented tags of the dpi protocol, give some tips, and finally let you examine the code of the already developed plugins. 

Don't forget to read "devdoc/Dpid.md".

# Dpi communication

## dillo => PI:

There're three ways:

* dpi tag
* static URL
* dynamic URL (with form data)

Note that all of them are in fact dpi tags, the division is made to separate some concepts. 

* The first one is for any specific dpi command sent fromthe browser to a PI. For example: `<dpi cmd='add_bookmark' url='http://here.org' title='Here!'>` 
* The second one usually refers an URL "inside" the PI's scope. It commands the PI to do something (usually to send back apage). For intance: `<dpi cmd='open_url' url='dpi:/bm/'>`. In this case the PI must react sending the main page for theu ser's bookmarks. 
* The third one is the most versatile. It sends back (to thee PI) all the data associated with a FORM that was most usually sent by the PI itself before. For instance: `<dpi cmd='open_url' url='dpi:/bm/modify?operation=modify&submit=submit.&s1=on'>` (all in a single line)

That's how the PI knows we want to modify the first section name of the bookmarks file. 

# PI => dillo

There're two ways:
* dpi tag
* HTML page

The first one is the generic mechanism and usually servesto command the browser. For instance: `<dpi cmd='send_status_message' msg='Bookmark added!'>`

The second one tells the browser we'll send an HTML page. `<dpi cmd='start_send_page' url='dpi:/bm/'>`

# The protocol

Amazingly (if you've already tried the bookmarks PI), all its functionality is carried on with these few dpi tags:

```
dillo => PI:
<dpi cmd='open_url' url='%s'>
<dpi cmd='add_bookmark' url='%s' title='%s'>
<dpi cmd='chat' msg='%s'>
```
```
PI => dillo:
<dpi cmd='start_send_page' url='%s'>
<dpi cmd='send_status_message' msg='%s'>
<dpi cmd='reload_request' url='%s'>
<dpi cmd='chat' msg='%s'>
```
So it is NOT that hard!

# Tips for developing a new PI

First, examine the above mentioned protocol tags, then read the code of `hello.c` ("Hello world" PI) and figure out its work. You should also have read Dpid.md at this point. 

After that, it'll be clear what the basic skeleton is, and how to send back a page to dillo. 

The next step is to make a FORM, get some data from the user, and to send back a new page that manipulates the input data. For this: 

* Design an HTML page with the form
* Design an HTML page with the desired answer skeleton
* Make your PI send the form as the main page (as an answer to "dpi:/mydpi/", for instance)

Once you have that, you'll need to process the input data: 

* Make your PI print what it receives so it becomes clear what you're dealing with.
* Either try to process it right away, or study how it's done in the `Bmsrv_parse_buf` function of the bookmarks PI. Now you have the parsed data:
* Manipulate it somehow
* Build the answer page and send it back

If you made this far, the rest will be clear enough from studying the commented bookmarks' code! If you don't want to make a form-based PI, but one that spawns another process you may start looking in the ftp PI.

# What's missing in this implementation

1) Some dpi commands (This is good in the sense of a protocol being finished when the last uneeded commands are removed! :)
2) PI start/initialization.
3) All the menu handling (from PI to browser) is to be defined (there're some ideas about these near the end)

# Dpi commands

From the set of dpi commands, I want to comment on two: 

start_send_page: `<dpi cmd='start_send_page' length='%d'>` 

This was meant to encapsulate HTML chunks of certain length. The final chunk should be marked with `length='0'` or something akin. 

The main purpose of it is to allow communication after the HTML page is sent. That way, for instance, the bookmarks plugin could send a staus message adding more information about a performed operation (as "Deleted 3 bookmarks"). 

The only reason I didn't code it from the start was to get to a working framework as fast as possible. It's not hard though. 

Currently the dpi framework uses `'start_send_page'` which assumes that all the following data, up to EOF, is part of the HTML page. 

`send_data`

This will be a generic way of exchanging information. Useful for sending/setting preferences for instance. Very similar to the previous command, and much like the current 'chat' command. 

BTW, the 'chat' command is not necessary (just gave a look to the funny and irrelevant talk between dillo and the bm PI!). It was just a way of testing bidirectional data exchange. If you need to send/request some data, feel free to use 'chat'until 'send_data' is implemented. 

# PI start/initialization

There's a lot more info about it in the following pages. A polished interface for registering/launching plugins is yet to be developed. 

We want dillo and dpid to be able to add, remove and upgrade plugins in a clear and transparent way. We're working on it... 

# Menu handling

Just read the following section!. 

# SECTION II
*(this is the draft part)* 

This section is mainly a gathering of ideas about what's not yet implemented: 

* Dpi commands 
* Menus 
* PI initialization 
* Plugins options 
* Plan 
* Future extensions 
* Final notes

# Dpi commands
*NOTE: this commands list is just a set of ideas. It doesn't mean they will be implemented. We gather them here just to keeptrack of the interesting ideas they bring.*

# dillo -> PI
```
CMD:DpiAbort::
```

Sent by dillo to abort an "in-progress" plugin. Dillo might send a "kill -9" command to the PI if it doesn't answer.(most probably dillo will ask the dpid to kill a PI, and the dpiditself will send a kill signal to the PI).

```
CMD:DpiBye::
```
> Note while editing: this seems to have been implemented: `<cmd='DpiBye' '>`

The plugin is commanded to quit (after it's done).

It may be used to end a "resident" PI that's doing nothing.Plugins can end and exit when finished or keep sleeping, but they MUST acknowledge dillo when they're done on a per client basis.

```
CMD  : DpiError::
```

Sent by dillo when a command is not understood.

# PI -> dillo

```
CMD  : DpiRequestInfo::
```
Sent to the browser to request information. For instance: 

* Dillo version
* title of current page
* URL of current page
* preferences (the whole preferences as text)
* All active colors (background, text, link, visited link)

```
CMD  : DpiSetData::
```

Sent to the browser to change its "state". Example: preferences, menus.

```
CMD  : DpiDone::
```

Sent by the PI when finished servicing a client.

# Menus

Menus need to be defined thinking on the needs of current and future PIs. The may not require menu entries (as the FTP PI), may require a single menu entry, or a whole menu, or a button.

The key point here is to provide simple support for menus, and not to complicate the protocol with seldom required features.

# simplified menu registration protocol

EG 

## Main goals

* a plugin may or may not want to be registered in the menus when initializing: menus are optional. 
* a plugin may want to change some or all its menus entries at runtime. 
* the plugins menu looks like this: there's a "Plugins" menu in dillo's menubar, where all plugins are shown, provided they asked for it during the init stage. Then it's up to the plugin to ask this entry to be an url or a submenu.

## Commands

```
:CMD  : DpiMenuMenu 
```

commands:- 
* insert: add an entry named <string> just after the entry ID. Dillo must answer with the new entry ID.
* delete: delete an entry ID and all dependent sub-menus.
* modify: modity the <string> of an entry.
* submenu: make an entry a submenu.
* url: give <string> as the url to be called when the menu entry is clicked.

> Note while editing in 2023: instead of this rpc-style approach, it might be better to be able for an application to be able to specify its menu entries _declaratively_ by supplying, eg, a blob of json, yaml, or xml.

# PI initialization

The main problem with running each PI everytime dillo starts is the added startup time. If, for instance, there's a PERL and a Python PI, the time increase is too much. We're working on a scheme that avoids running each plugin when dillo starts. It has a "pluginsrc" kind of file with information about each PI. The whole work is done by dpid, but there'll be a control program for the user interface. Something like: 

```
dpidc [register | upgrade | stop | ...]
```

`dpidc` communicates with `dpid` using the same service request socket that dillo currently uses. All the operations will bedefined with dpip tags. 

What I like from this approach is that it is very flexible and can be implemented incrementally ("dpidc register" is enough to start).

It also avoids the burden of having to periodically check the dpis directory structure for changes or updates. 

It also gives shell scripts an easy way to do the "dirty" work of installing dpis; this may help building a dillo package for certain distros. 

For instance, these commands may be added to the protocol:

# dillo -> dpi

```
CMD  : DpiInit::
```

It should include some challenge data to assert it's a dpi.

# dpi->dillo

```
CMD  : DpiInitAnswer::
```

Data is composed of a list of `name=value` pairs separated with ';' just like in an URL (it must answer the challenge). Example: 

```
Name="bookmarks";prefix="bm";MenuEntry="View Bookmarks"
```

# Plugins options

There're two different things here, the PI registration data (managed by `dpid` in the 'pluginsrc' file for every PI), and the specific options a specific PI-program may provide for tuning its behaviour. The later one should be managed by the PI program itself

# Plan

Currently the dpi framework has working dpis for: `bookmarks`,`ftp`, `downloads` and `hello`. 

> Note while editing: it also has some other dpis for other protocols like Gemini and Gopher, DAT, and others. See: https://groups.google.com/g/dillo/c/WGEMg7AXN4o 

The plan is to polish & stabilize both, the dpis and the framwork, with a view to 0.8.0 release.

# Future extensions (needs a lot more thought)

1) Postfixed call to a Dillo-plugin

Dillo plugins registered as such will be called if the loadedpage's <extension> in "<url>.<extension>" matches a Dillo-plugin registration, or if the PI has registered the same MIME type of that content, and thus the PI acts as a file-processing filter. 

Dillo will call the Dillo-plugin sending to it the whole loaded file, and expecting some data back. This can be used as a file-to-html filter. Example: `http://my.server.org/mydirectory/myfile.rtf` will render the rtf file as html if a Dillo-plugin has registered itself as dealing with "rtf" files. 

# Final notes

The draft part of this material is not "written on stone", but provided as a structural basis on which to develop the simple PI protocol. Please take it with a pinch of salt, in the best spirit of a RFC. As you can see, there's plenty of material here, and discussion threads can get very large if posts are not carefully thought of. 

Please take your time to study and fully understand the material, and only submit well backed/tested ideas. 

Thanks a lot to all of those that have contributed in making dpi1 possible!
