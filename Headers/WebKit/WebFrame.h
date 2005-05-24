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

@interface WebFrame : NSObject
{
	IBOutlet NSScrollView *scroll;
	IBOutlet NSTextView *text;
	
//	NSURLHandle *handle;
//	NSMutableData *loadedData;
	WebDataSource *dataSource;
}

- (id) initWithName:(NSString *) frameName webFrameView:(WebFrameView *) frameView webView:(WebView *) webView;
- (void) loadRequest:(NSURLRequest *) request;
- (void) stopLoading;
- (void) reload;
- (WebDataSource *) dataSource;
- (WebDataSource *) provisionalDataSource;

@end
