/* simplewebkit
   WebFrameLoadDelegate.h

   Copyright (C) 2007-2010 Free Software Foundation, Inc.

   Author: Dr. H. Nikolaus Schaller

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public
   License along with this library; see the file COPYING.LIB.
   If not, write to the Free Software Foundation,
   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
*/

#import <Foundation/Foundation.h>
#import <AppKit/NSImage.h>

@class WebView, WebFrame, WebScriptObject;

@protocol WebFrameLoadDelegate

- (void) webView:(WebView *) sender didReceiveTitle:(NSString *) title forFrame:(WebFrame *) frame;
- (void) webView:(WebView *) sender didStartProvisionalLoadForFrame:(WebFrame *) frame;
- (void) webView:(WebView *) sender didCommitLoadForFrame:(WebFrame *) frame;
- (void) webView:(WebView *) sender willCloseFrame:(WebFrame *) frame;
- (void) webView:(WebView *) sender didFinishLoadForFrame:(WebFrame *) frame;
- (void) webView:(WebView *) sender willPerformClientRedirectToURL:(NSURL *) url delay:(NSTimeInterval) seconds fireDate:(NSDate *) date forFrame:(WebFrame *) frame;
- (void) webView:(WebView *) sender didCancelClientRedirectForFrame:(WebFrame *) frame;

// not yet called

- (void) webView:(WebView *) sender didChangeLocationWithinPageForFrame:(WebFrame *) frame;
- (void) webView:(WebView *) sender didFailLoadWithError:(NSError *) error forFrame:(WebFrame *) frame;
- (void) webView:(WebView *) sender didFailProvisionalLoadWithError:(NSError *) error forFrame:(WebFrame *) frame;
- (void) webView:(WebView *) sender didReceiveIcon:(NSImage *) image forFrame:(WebFrame *) frame;
- (void) webView:(WebView *) sender serverRedirectedForDataSource:(WebFrame *) frame;	// deprecated
- (void) webView:(WebView *) sender didReceiveServerRedirectForProvisionalLoadForFrame:(WebFrame *) frame;	// new
- (void) webView:(WebView *) sender windowScriptObjectAvailable:(WebScriptObject *) script;	// deprecated in 10.4.11
- (void) webView:(WebView *) sender didClearWindowObject:(WebScriptObject *) script forFrame:(WebFrame *) frame;	// introduced in 10.4.11

@end

// used as frameLoadDelegate of WebView

@interface NSObject (WebFrameLoadDelegate) <WebFrameLoadDelegate>

@end

