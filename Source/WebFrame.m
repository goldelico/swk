//
//  WebFrame.m
//  mySTEP
//
//  Created by Dr. H. Nikolaus Schaller on Mon Jan 05 2004.
//  Copyright (c) 2004 DSITRI. All rights reserved.
//

#import <WebKit/WebFrame.h>

@implementation WebFrame

- (id) initWithName:(NSString *) n webFrameView:(WebFrameView *) frameView webView:(WebView *) webView
{
    self=[super init];
    if(self)
		{ // If an error occurs here, send a [self release] message and return nil.
		name=[n retain];
		frameview=[frameView retain];
		webview=[webView retain];
		children=[[NSMutableArray alloc] initWithCapacity:5];
		}
    return self;
}

- (void) dealloc;
{
	[self stopLoading];	// cancel any pending actions 
	[name release];
	[frameview release];
	[webview release];
	[children release];
	[request release];
	[dataSource release];
	[super dealloc];
}

- (void) loadRequest:(NSURLRequest *) req;
{
	request=[req copy];
	[self reload];
}

- (void) stopLoading;
{
}

- (void) reload;
{
	// create a WebDataSource to load
}

- (void) loadAlternateHTMLString:(NSString *) string baseURL:(NSURL *) url forUnreachableURL:(NSURL *) unreach;
{
}

- (void) loadArchive:(WebArchive *) archive;
{
}

- (void) loadData:(NSData *) data MIMEType:(NSString *) mime textEncodingName:(NSString *) encoding baseURL:(NSURL *) url;
{
}

- (void) loadHTMLString:(NSString *) string baseURL:(NSURL *) url;
{
}

- (WebFrame *) findFrameNamed:(NSString *) n;
{
	if([n isEqualToString:@"_self"] || [n isEqualToString:@"_current"])
		return self;
	if([n isEqualToString:@"_parent"])
		return parent?parent:self;
	if([n isEqualToString:@"_top"])
		{
		WebFrame *f=self;
		while([f parentFrame])
			f=[f parentFrame];	// search top element
		return f;
		}
	if([n isEqualToString:name])
		return self;
	// search descendents and parents
	return nil;
}

- (WebDataSource *) dataSource; { return dataSource; }
- (WebDataSource *) provisionalDataSource; { return nil; }
- (WebFrame *) parentFrame; { return parent; }
- (NSArray *) childFrames; { return children; }
- (WebFrameView *) frameView; { return frameview; }
- (WebView *) webView; { return webview; }
- (NSString *) name; { return name; }
- (DOMDocument *) DOMDocument; { return nil; }
- (DOMHTMLElement *) frameElement; { return nil; }

@end
