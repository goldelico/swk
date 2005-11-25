//
//  WebFrameView.m
//  mySTEP
//
//  Created by Dr. H. Nikolaus Schaller on Mon Jan 05 2004.
//  Copyright (c) 2004 DSITRI. All rights reserved.
//

#import <WebKit/WebFrameView.h>
#import <WebKit/WebFrame.h>

@implementation WebFrameView

// This private method generates a subview hierarchy using the webFrame hierarchy.
// The first level below this WebFrameView is a NSScrollView (if we allow scrolling).
// The elements to be displayed are laid out properly in the subviews of that scroll view.
// They can be e.g. NSTextView, NSPopUpButton, NSTextField, NSButton, and WebFrameView depending
// on the tags found in the HTML source

- (id) _initWithFrame:(NSRect) f documentView:(NSView *) docview webFrame:(WebFrame *) webFrame;
{
	self=[super initWithFrame:f];
	if(self)
		{
		_webFrame=[webFrame retain];
		_view=[docview retain];
		[self addSubview:docview];
		// create subviews as required by WebFrame
		}
	return self;
}

- (void) dealloc;
{
	[_webFrame release];
	[_view release];
	[super dealloc];
}

- (BOOL) allowsScrolling; { return NO; }	// check documentView
- (WebFrame *) webFrame; { return _webFrame; }
- (NSView *) documentView; { return _view; }

- (void) setAllowsScrolling:(BOOL) flag;
{
	// modify embedded NSScrollView
}


@end
