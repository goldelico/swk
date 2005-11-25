//
//  WebFrame.h
//  mySTEP
//
//  Created by Dr. H. Nikolaus Schaller on Mon Jan 05 2004.
//  Copyright (c) 2004 DSITRI. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <Foundation/NSURLRequest.h>
#import <WebKit/WebDataSource.h>
#import <WebKit/WebFrameView.h>
#import <WebKit/WebView.h>

typedef void DOMHTMLElement;	// not yet implemented
typedef void DOMDocument;		// not yet implemented

@class WebArchive;		// not yet implemented

@interface WebFrame : NSObject
{
	WebDataSource *dataSource;
	NSString *name;				// our name
	WebFrameView *frameview;	// our frame view
	WebView *webview;			// our web view
	WebFrame *parent;
	NSMutableArray *children;	// loading will create children
	NSURLRequest *request;
}

- (id) initWithName:(NSString *) frameName webFrameView:(WebFrameView *) frameView webView:(WebView *) webView;
- (void) stopLoading;
- (void) reload;
- (WebDataSource *) dataSource;
- (WebDataSource *) provisionalDataSource;
- (void) loadAlternateHTMLString:(NSString *) string baseURL:(NSURL *) url forUnreachableURL:(NSURL *) unreach;
- (void) loadArchive:(WebArchive *) archive;
- (void) loadData:(NSData *) data MIMEType:(NSString *) mime textEncodingName:(NSString *) encoding baseURL:(NSURL *) url;
- (void) loadHTMLString:(NSString *) string baseURL:(NSURL *) url;
- (void) loadRequest:(NSURLRequest *) request;

- (WebFrame *) parentFrame;
- (NSArray *) childFrames;
- (WebFrameView *) frameView;
- (WebView *) webView;
- (WebFrame *) findFrameNamed:(NSString *) name;
- (NSString *) name;
- (DOMDocument *) DOMDocument;
- (DOMHTMLElement *) frameElement;

@end
