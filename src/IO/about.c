/*
 * File: about.c
 *
 * Copyright (C) 1999-2007 Jorge Arellano Cid <jcid@dillo.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 */

#include <config.h>

/*
 * HTML text for startup screen
 */
const char *const AboutSplash=
"<!DOCTYPE HTML PUBLIC '-//W3C//DTD HTML 4.01 Transitional//EN'>\n"
"<html>\n"
"<head>\n"
"<title>Splash screen for dillo-" VERSION "</title>\n"
"</head>\n"
"<body bgcolor='#778899' text='#000000' link='#000000' vlink='#000000'>\n"
"\n"
"\n"
"<!--   the head of the page   -->\n"
"\n"
"<table width='100%' border='0' cellspacing='1' cellpadding='3'>\n"
" <tr><td>\n"
"  <table border='1' cellspacing='1' cellpadding='0'>\n"
"   <tr>\n"
"   <td bgcolor='#000000'>\n"
"    <table width='100%' border='0' bgcolor='#ffffff'>\n"
"    <tr>\n"
"     <td valign='top' align='left'>\n"
"      <h1>&nbsp;Welcome to Dillo " VERSION "&nbsp;</h1>\n"
"    </table>\n"
"  </table>\n"
"</table>\n"
"\n"
"<br>\n"
"\n"
"\n"
"<!-- the main layout table, definition -->\n"
"\n"
"<table width='100%' border='0' cellspacing='0' cellpadding='0'>\n"
"<tr><td valign='top' width='150' align='center'>\n"
"\n"
"\n"
"<!--   The navigation bar   -->\n"
"\n"
"<table border='0' cellspacing='0' cellpadding='0' width='140' bgcolor='#000000'>\n"
"<tr>\n"
" <td>\n"
"  <table width='100%' border='0' cellspacing='1' cellpadding='3'>\n"
"  <tr>\n"
"   <td colspan='1' bgcolor='#CCCCCC'>Dillo\n"
"  <tr>\n"
"   <td bgcolor='#FFFFFF'>\n"
"    <table border='0' cellspacing='0' cellpadding='5'><tr><td>\n"
"    <table border='0' cellspacing='0' cellpadding='2'><tr>\n"
"    <td>\n"
"    <td>\n"
"     <a href='http://www.dillo.org/dillo3-help.html'>\n"
"     Help</a>\n"
"    <tr>\n"
"    <td>&nbsp;&nbsp;\n"
"    <td>\n"
"     <a href='http://www.dillo.org/'>Home</a>\n"
"    <tr>\n"
"    <td>&nbsp;&nbsp;\n"
"    <td>\n"
"     <a href='http://www.dillo.org/funding/objectives.html'>\n"
"     Objectives</a>\n"
"    <tr>\n"
"    <td>&nbsp;&nbsp;\n"
"    <td>\n"
"     <a href='http://hg.dillo.org/dillo/raw-file/tip/ChangeLog'>\n"
"     ChangeLog</a>\n"
"    <tr>\n"
"    <td>&nbsp;&nbsp;\n"
"    <td>\n"
"     <a href='http://www.dillo.org/interview.html'>\n"
"       Interview</a>\n"
"    <tr>\n"
"    <td>&nbsp;&nbsp;\n"
"    <td>\n"
"     <a href='http://www.dillo.org/D_authors.html'>\n"
"     Authors</a>\n"
"    <tr>\n"
"    <td>&nbsp;&nbsp;\n"
"    <td>\n"
"     <a href='http://www.dillo.org/donations.html'>\n"
"     Donate</a>\n"
"    </table>\n"
"    </table>\n"
"  </table>\n"
"</table>\n"
"\n"
"<br>\n"
"\n"
"<table border='0' cellspacing='0' cellpadding='0' width='140' bgcolor='#000000'>\n"
"<tr>\n"
" <td>\n"
"  <table width='100%' border='0' cellspacing='1' cellpadding='3'>\n"
"  <tr>\n"
"    <td colspan='1' bgcolor='#CCCCCC'>News\n"
"\n"
"  <tr>\n"
"   <td bgcolor='#FFFFFF'>\n"
"    <table border='0' cellspacing='0' cellpadding='5'><tr><td>\n"
"    <table border='0' cellpadding='2'>\n"
"    <tr>\n"
"    <td>&nbsp;&nbsp;\n"
"    <td>\n"
"     <a href='http://lwn.net/'>LWN</a>\n"
"    <tr>\n"
"    <td>&nbsp;&nbsp;\n"
"    <td>\n"
"     <a href='http://slashdot.org/'>Slashdot</a>\n"
"    <tr>\n"
"    <td>&nbsp;&nbsp;\n"
"    <td>\n"
"     <a href='http://www.commondreams.org/'>C.&nbsp;Dreams</a>\n"
"    <tr>\n"
"    <td>&nbsp;&nbsp;\n"
"    <td>\n"
"     <a href='http://www.voltairenet.org/en'>VoltaireNet</a>\n"
"    <tr>\n"
"    <td>&nbsp;&nbsp;\n"
"    <td>\n"
"     <a href='http://www.nexusmagazine.com/'>Nexus&nbsp;M.</a>\n"
"    </table>\n"
"    </table>\n"
"  </table>\n"
"</table>\n"
"\n"
"<br>\n"
"\n"
"<table border='0' cellspacing='0' cellpadding='0' width='140' bgcolor='#000000'>\n"
"<tr>\n"
" <td>\n"
"  <table width='100%' border='0' cellspacing='1' cellpadding='3'>\n"
"  <tr>\n"
"   <td colspan='1' bgcolor='#CCCCCC'>Additional Stuff\n"
"\n"
"  <tr>\n"
"   <td bgcolor='#FFFFFF'>\n"
"    <table border='0' cellspacing='0' cellpadding='5'><tr><td>\n"
"    <table border='0' cellpadding='2'><tr>\n"
"    <td>&nbsp;&nbsp;\n"
"    <td><a href='http://www.gutenberg.org/'>P.&nbsp;Gutenberg</a>\n"
"    <tr>\n"
"    <td>&nbsp;&nbsp;\n"
"    <td><a href='http://freecode.com/'>Freecode</a>\n"
"    <tr>\n"
"    <td>&nbsp;&nbsp;\n"
"    <td><a href='http://www.gnu.org/gnu/thegnuproject.html'>GNU\n"
"     project</a>\n"
"    <tr>\n"
"    <td>&nbsp;&nbsp;\n"
"    <td><a href='http://www.linuxfund.org/'>LinuxFund</a>\n"
"    </table>\n"
"    </table>\n"
"  </table>\n"
"</table>\n"
"\n"
"<br>\n"
"\n"
"<table border='0' cellspacing='0' cellpadding='0' width='140' bgcolor='#000000'>\n"
"<tr>\n"
" <td>\n"
"   <table width='100%' border='0' cellspacing='1' cellpadding='3'>\n"
"   <tr>\n"
"    <td colspan='1' bgcolor='#CCCCCC'>Essential Readings\n"
"\n"
"   <tr>\n"
"    <td bgcolor='#FFFFFF'>\n"
"     <table border='0' cellspacing='0' cellpadding='5'><tr><td>\n"
"     <table border='0' cellpadding='2'>\n"
"     <tr><td>&nbsp;&nbsp;\n"
"     <td><a href='http://www.violence.de'>Peace&amp;Violence</a>\n"
"     <tr><td>&nbsp;&nbsp;\n"
"     <td><a href='http://www.gnu.org/philosophy/right-to-read.html'>\n"
"      Right to Read</a>\n"
"     </table>\n"
"     </table>\n"
"   </table>\n"
"</table>\n"
"\n"
"<table border='0' width='100%' cellpadding='0' cellspacing='0'><tr><td height='10'></table>\n"
"\n"
"\n"
"<!-- the main layout table, a small vertical spacer -->\n"
"\n"
"<td width='20'><td valign='top'>\n"
"\n"
"\n"
"<!--   Main Part of the page   -->\n"
"\n"
"<table border='0' cellpadding='0' cellspacing='0' align='center' bgcolor='#000000' width='100%'><tr><td>\n"
"<table border='0' cellpadding='5' cellspacing='1' width='100%'>\n"
"<tr>\n"
" <td bgcolor='#CCCCCC'>\n"
"  <h4>Free Software</h4>\n"
"<tr>\n"
" <td bgcolor='#FFFFFF'>\n"
"  <table border='0' cellspacing='0' cellpadding='5'><tr><td>\n"
"  <p>\n"
"  The Dillo web browser is Free Software under the terms of version 3 of\n"
"  the <a href='http://www.gnu.org/licenses/gpl.html'>GPL</a>.\n"
"  This means you have four basic freedoms:\n"
"  <ul>\n"
"   <li>Freedom to use the program any way you see fit.\n"
"   <li>Freedom to study and modify the source code.\n"
"   <li>Freedom to make backup copies.\n"
"   <li>Freedom to redistribute it.\n"
"  </ul>\n"
"  The GPL is the legal mechanism that gives you these freedoms.\n"
"  It also protects you from having them taken away: any derivative work\n"
"  based on the program must be under GPLv3 as well.<br>\n"
"  </table>\n"
"</table>\n"
"</table>\n"
"\n"
"<br>\n"
"\n"
"<table border='0' cellpadding='0' cellspacing='0' align='center' bgcolor='#000000' width='100%'><tr><td>\n"
"<table border='0' cellpadding='5' cellspacing='1' width='100%'>\n"
"<tr>\n"
" <td bgcolor='#CCCCCC'>\n"
"  <h4>Notes</h4>\n"
"<tr>\n"
" <td bgcolor='#FFFFFF'>\n"
"  <table border='0' cellspacing='0' cellpadding='5'>\n"
"  <tr>\n"
"   <td>\n"
"<ul>\n"
" <li> Read the <a href='http://www.dillo.org/dillo3-help.html'>help</a>,\n"
"      it's short.\n"
" <li> There's a\n"
"   <a href='http://www.dillo.org/dillorc'>dillorc</a>\n"
"   (readable config) file inside the tarball. It is well-commented\n"
"   and has plenty of options to customize dillo, so <STRONG>copy\n"
"   it</STRONG> to your <STRONG>~/.dillo/</STRONG> directory, and\n"
"   modify it to your taste.\n"
" <li> The right mouse button brings up a context-sensitive menu\n"
"   (available on pages, links, images, forms, the Back and Forward buttons,\n"
"    and the bug meter).\n"
" <li> Cookies are disabled by default for privacy. To log into certain\n"
"   sites, you may need to <a href='http://www.dillo.org/Cookies.txt'>enable\n"
"   cookies selectively</a>.\n"
" <li> To stop third-party ads and tracking, you can use a\n"
"   ~/.dillo/<a href='http://www.dillo.org/domainrc'>domainrc</a>/ file.\n"
" <li> Frames, Java and Javascript are not supported.\n"
" <li> This release is mainly intended for <strong>developers</strong>\n"
"   and <strong>advanced users</strong>.\n"
" <li> Documentation for developers is in the <CODE>/doc</CODE>\n"
"   dir inside the tarball; you can find directions on everything\n"
"   else at the home page.\n"
"</ul>\n"
"  </table>\n"
"</table>\n"
"</table>\n"
"\n"
"<br>\n"
"\n"
"<table border='0' cellpadding='0' cellspacing='0' align='center' bgcolor='#000000' width='100%'><tr><td>\n"
"<table border='0' cellpadding='5' cellspacing='1' width='100%'>\n"
"<tr>\n"
" <td bgcolor='#CCCCCC'>\n"
"  <h4>Release overview</h4>\n"
"  ---- --, 2015\n"
"<tr>\n"
" <td bgcolor='#FFFFFF'>\n"
"  <table border='0' cellspacing='0' cellpadding='5'>\n"
"  <tr>\n"
"   <td>\n"
"<p>\n"
"Among the changes in dillo-3.0.5 are:\n"
"<ul>\n"
"<li>Image buffer/cache improvements.\n"
"<li>Fix for segfault when there's no dpid and view source is requested.\n"
"<li>Fix view-source dpi to handle null characters correctly.\n"
"<li>Made view-source dpi use CSS formatting (it's shorter and cleaner).\n"
"<li>Crosscompile/buildroot-friendly fltk-config test.\n"
"<li>Fix X11 icon name.\n"
"<li>In location bar, tend toward showing beginning of URL instead of end.\n"
"<li>Handle irix's version of vsnprintf().\n"
"<li>INPUT, TEXTAREA placeholder attribute.\n"
"<li>Better notification when user's domainrc settings block page\n"
"    redirection.\n"
"<li>Fix bug with font_factor preference and CSS font-size:(larger|smaller).\n"
"<li>Recognize Menu key in keysrc.\n"
"<li>HTTPS: change cipher list to \"ALL:!aNULL:!eNULL:!LOW:!EXPORT40:!RC4\",\n"
"    disable SSL3, disable TLS compression.\n"
"<li>Avoid requesting background images if an ancestor has display:none.\n"
"<li>Ignore built-in search url if any are specified in dillorc.\n"
"</ul>\n"
"<p>\n"
"...that shouldn't have to wait until dillo-3.1 is ready with its floating\n"
"elements and assorted good things.\n"
"<p>\n"
"  </table>\n"
"</table>\n"
"</table>\n"
"\n"
"\n"
"<!-- the main layout table, a small vertical spacer -->\n"
"\n"
"<td width='20'>\n"
"\n"
"\n"
"\n"
"<!--   The right column (info)   -->\n"
"<td valign='top' align='center'>\n"
"\n"
"\n"
"\n"
"<!-- end of the main layout table -->\n"
"\n"
"\n"
"</table>\n"
"\n"
"<!--   footnotes   -->\n"
"\n"
"<br><br><center>\n"
"<hr size='2'>\n"
"<hr size='2'>\n"
"</center>\n"
"</body>\n"
"</html>\n";

