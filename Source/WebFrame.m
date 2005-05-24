//
//  WebFrame.m
//  mySTEP
//
//  Created by Dr. H. Nikolaus Schaller on Mon Jan 05 2004.
//  Copyright (c) 2004 DSITRI. All rights reserved.
//

#import <WebKit/WebFrame.h>

@implementation WebFrame

// - (id)initWithName:(NSString *)frameName webFrameView:(WebFrameView *)frameView webView:(WebView *)webView

- (id)init // withWebView???
{
    self = [super init];
    if (self)
		{ // If an error occurs here, send a [self release] message and return nil.
		}
    return self;
}

- (void) dealloc;
{
	[self stopLoading];	// cancel any pending actions 
	[super dealloc];
}

@end
