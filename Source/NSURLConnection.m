//
//  NSURLConnection.m
//  mySTEP
//
//  Created by Dr. H. Nikolaus Schaller on Mon Jan 05 2004.
//  Copyright (c) 2004 DSITRI. All rights reserved.
//

#import <Foundation/NSURLConnection.h>


@implementation NSURLConnection

#ifdef __mySTEP__

- (void) loadRequest:(NSURLRequest *) request;
{ // trigger the request and make myself the delegate
	NSString *referer=nil;
	_handle=[[[request URL] URLHandleUsingCache:YES] retain];
	//	[u loadResourceDataNotifyingClient:self usingCache:YES];	// load in background from cache
	if(!_handle)
		{
	//	[self setStatusLine:[NSString stringWithFormat:@"can't load: %@", [self getLocation]]];
	//	[reload setState:NSOffState];
		return;
		}
	[_handle addClient:self];	// I want to receive notifications
//	referer=[self getReferer];
	if(referer)
		{
		referer=[[NSURL URLWithString:referer] absoluteString];	// get as absolute string
		[_handle writeProperty:referer forKey:@"Referer"];
		NSLog(@"referer=%@", referer);
		}
	[_handle writeProperty:@"myAfrica" forKey:@"Browsertype"];
	//	[_handle writeProperty:@"myAfrica" forKey:@"Browsertype"];	// setup cookies to send
	[_handle loadInBackground];	// and start loading
}

- (void) cancel;
{ // stop loading
	[_handle cancelLoadInBackground];	// ignored if _handle=nil
}

// notification _handler

- (void) URL_handleResourceDidBeginLoading:(NSURLHandle *)sender
{
	_loadedData=[[NSMutableData dataWithCapacity:1000] retain];  // create data container
}

- (void) URL_handleResourceDidCancelLoading:(NSURLHandle *)sender
{
	[_handle removeClient:self];	// no longer receive notifications - may be cached!
	[_handle release];
	_handle=nil;
	[_loadedData release];	// release previous data
}

- (void) URL_handleResourceDidFinishLoading:(NSURLHandle *)sender
{
	[_handle removeClient:self];	// no longer receive notifications - may be cached!
	[_handle release];
	_handle=nil;
	[_loadedData release];	// release previous data
}

- (void) URL_handle:(NSURLHandle *)sender resourceDataDidBecomeAvailable:(NSData *)newBytes
{
	//	NSLog(@"new data (%u)", [newBytes length]);
	[_loadedData appendData:newBytes];
	// use the basic rendering engine
	// find <title>...</title> in loaded data and set window title
}

- (void) URL_handle:(NSURLHandle *)sender resourceDidFailLoadingWithReason:(NSString *)reason
{
	// notify error
	[self URL_handleResourceDidFinishLoading:sender];
}

#endif

@end
