//
//  WebDataSource.m
//  mySTEP
//
//  Created by Dr. H. Nikolaus Schaller on Mon Jan 05 2004.
//  Copyright (c) 2004 DSITRI. All rights reserved.
//

#import <WebKit/WebDataSource.h>

@implementation WebDataSource

- (id) initWithRequest:(NSURLRequest *) request;
{
    self = [super init];
    if (self)
		{ // If an error occurs here, send a [self release] message and return nil.
		// store requested URL
		}
    return self;
}

- (void) dealloc;
{
	[self stopLoading];	// cancel any pending actions 
	[super dealloc];
}

- (void) load;
{
	NSString *referer=@"";
	[self stopLoading];	// stop if already loading something
	NSLog(@"load url %@", [[request URL] absoluteString]);
	// check for mailto: URL
	// check for about: URL
	handle=[[[request URL] URLHandleUsingCache:YES] retain];
	//	[u loadResourceDataNotifyingClient:self usingCache:YES];	// load in background from cache
	if(!handle)
		{
//		[self setStatusLine:[NSString stringWithFormat:@"can't load: %@", [self getLocation]]];
//		[reload setState:NSOffState];
		return;
		}
	[handle addClient:self];	// I want to receive notifications
//	referer=[self getReferer];
	if(referer)
		{
		referer=[[NSURL URLWithString:referer] absoluteString];	// get as absolute string
		[handle writeProperty:referer forKey:@"Referer"];
		NSLog(@"referer=%@", referer);
		}
	[handle writeProperty:@"myAfrica" forKey:@"Browsertype"];
	// setup cookies to send
	// [handle writeProperty:@"xyz" forKey:@"abc"];	
//	[reload setState:NSOffState];
	[handle loadInBackground];	// and start loading
								// set action of reload button to @selector(stopLoading:)
}

- (void) stopLoading;
{ // stop loading
	[handle cancelLoadInBackground];	// ignored if handle=nil
}

- (void) reload;
{
	NIMP;
}

// protocol

- (void) URLHandleResourceDidBeginLoading:(NSURLHandle *)sender
{
	loadedData=[[NSMutableData dataWithCapacity:1000] retain];
//	[self setStatusLine:[NSString stringWithFormat:@"loading..."]];
}

- (void)URLHandleResourceDidCancelLoading:(NSURLHandle *)sender
{
//	[self setStatusLine:[NSString stringWithFormat:@"cancelled."]];
//	[reload setState:NSOffState];
	[handle removeClient:self];	// no longer receive notifications - may be cached!
	[handle release];
	handle=nil;
	[loadedData release];	// release previous data
}

- (void)URLHandleResourceDidFinishLoading:(NSURLHandle *)sender
{
//	[self setStatusLine:[NSString stringWithFormat:@"done."]];
//	[reload setState:NSOffState];
	[handle removeClient:self];	// no longer receive notifications - may be cached!
	[handle release];
	handle=nil;
	[loadedData release];	// release previous data
}

- (void)URLHandle:(NSURLHandle *)sender resourceDataDidBecomeAvailable:(NSData *)newBytes
{
	//	NSLog(@"new data (%u)", [newBytes length]);
	[loadedData appendData:newBytes];
	// use the basic rendering engine
	// find <title>...</title> in loaded data and set window title
	// should call delegate!!!
//	[[text textStorage] setAttributedString:[[[NSAttributedString alloc] initWithHTML:loadedData documentAttributes:nil] autorelease]];
}

- (void)URLHandle:(NSURLHandle *)sender resourceDidFailLoadingWithReason:(NSString *)reason
{
//	[self setStatusLine:[NSString stringWithFormat:@"load failed: %@", reason]];
//	[reload setState:NSOffState];
	[handle removeClient:self];	// no longer receive notifications - may be cached!
	[handle release];
	handle=nil;
	[loadedData release];	// release previous data
}

@end
