//
//  WebView.h
//  mySTEP
//
//  Created by Dr. H. Nikolaus Schaller on Mon Jan 05 2004.
//  Copyright (c) 2004 DSITRI. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <Foundation/NSURLRequest.h>

@class WebView;
@class WebFrame;

@interface NSObject (WebViewUIDelegate)
- (WebView *) webView:(WebView *)sender createWebViewWithRequest:(NSURLRequest *)request;
- (void) webViewShow:(WebView *)sender;
- (void) webView:(WebView *)sender didStartProvisionalLoadForFrame:(WebFrame *)frame;
- (void) webView:(WebView *)sender didReceiveTitle:(NSString *)title forFrame:(WebFrame *)frame;
- (void) webView:(WebView *)sender didFinishLoadForFrame:(WebFrame *)frame;
@end

@interface WebView : NSView
{
	WebFrame *_mainFrame;
	id _uiDelegate;
}

- (WebFrame *) mainFrame;
- (void) setUIDelegate:(id) uiDelegate;
- (void) setGroupName:(NSString *) str;
- (void) setMaintainsBackForwardList:(BOOL) flag;
- (void) setCustomUserAgent:(NSString *) agent;
- (void) setApplicationNameForUserAgent:(NSString *) name;

- (BOOL) canGoBack;
- (BOOL) canGoForward;

- (double) estimatedProgress;

- (IBAction) takeStringURLFrom:(id) sender; // anything responding to stringValue
- (IBAction) reload:(id) sender;
- (IBAction) stopLoading:(id) sender;
- (IBAction) goBack:(id) sender;
- (IBAction) goForward:(id) sender;
- (IBAction) makeTextLarger:(id) sender;
- (IBAction) makeTextSmaller:(id) sender;

@end
