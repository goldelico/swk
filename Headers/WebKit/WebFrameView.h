//
//  WebFrameView.h
//  mySTEP
//
//  Created by Dr. H. Nikolaus Schaller on Mon Jan 05 2004.
//  Copyright (c) 2004 DSITRI. All rights reserved.
//

#import <Cocoa/Cocoa.h>
@class WebFrame;

@interface WebFrameView : NSView
{
	NSScrollView *_view;		// the display element (i.e. a scroll view)
	WebFrame *_webFrame;			// the frame we belong to
}

// This private method generates a subview hierarchy using the webFrame hierarchy.
// The first level below this WebFrameView is a NSScrollView (if we allow scrolling).
// The elements to be displayed are laid out properly in the subviews of that scroll view.
// They can be e.g. NXTextView, NSPopUpButton, NSTextField, NSButton, and WebFrameView depending
// on the tags found in the HTML source

- (id) _initWithFrame:(NSRect) frame documentView:(NSView *) docview webFrame:(WebFrame *) webFrame;

- (BOOL) allowsScrolling;
- (WebFrame *) webFrame;
- (NSView *) documentView;
- (void) setAllowsScrolling:(BOOL) flag;

@end
