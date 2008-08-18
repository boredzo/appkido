/*
 * AKSavedWindowState.h
 *
 * Created by Andy Lee on Sun Jun 15 2003.
 * Copyright (c) 2003, 2004 Andy Lee. All rights reserved.
 */

#import <Foundation/Foundation.h>

@class AKWindowLayout;
@class AKDocLocator;

/*!
 * @class       AKSavedWindowState
 * @abstract    Used to remember a browser window's display state between
 *              launches of the app.
 * @discussion  Remembers two things: the window's visual layout info, and
 *              what doc it was displaying.
 */
@interface AKSavedWindowState : NSObject
{
    NSString *_platformName;
    AKWindowLayout *_savedWindowLayout;
    AKDocLocator *_savedDocLocator;
}

//-------------------------------------------------------------------------
// Preferences
//-------------------------------------------------------------------------

+ (AKSavedWindowState *)fromPrefDictionary:(NSDictionary *)prefDict;

- (NSDictionary *)asPrefDictionary;

//-------------------------------------------------------------------------
// Getters and setters
//-------------------------------------------------------------------------

- (NSString *)platformName;
- (void)setPlatformName:(NSString *)platformName;

- (AKWindowLayout *)savedWindowLayout;
- (void)setSavedWindowLayout:(AKWindowLayout *)windowLayout;

- (AKDocLocator *)savedDocLocator;
- (void)setSavedDocLocator:(AKDocLocator *)docLocator;

@end
