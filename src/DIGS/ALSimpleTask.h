//
//  ALSimpleTask.h
//  ALUtilities
//
//	Copyright (c) 2011 Andy Lee
//
//	Permission is hereby granted, free of charge, to any person obtaining a copy of this software
//	and associated documentation files (the "Software"), to deal in the Software without restriction,
//	including without limitation the rights to use, copy, modify, merge, publish, distribute,
//	sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
//	furnished to do so. Attribution is not required for either source or binary forms of the Software.
//
//	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
//	BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
//	NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
//	DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//

#import <Foundation/Foundation.h>

/*!
 * Thin wrapper around NSTask that runs a command and collects its output. Runs
 * the command synchronously, so you might want to wrap this in an NSOperation.
 * Is meant to be used just once, like NSTask.
 */
@interface ALSimpleTask : NSObject

/*! Throws an exception (well, actually NSTask throws it) if args is nil. */
- (id)initWithCommandPath:(NSString *)commandPath arguments:(NSArray *)args;

/*!
 * Runs the command synchronously. Returns NO if the command fails to launch.
 * You can only call this once.
 */
- (BOOL)runTask;

/*!
 * Returns the combined stdout and stderr output of the command. If the command
 * failed to launch, contains a UTF-8 string that gives the reason why. You can
 * call this before the task completes.
 */
- (NSData *)outputData;

/*!
 * Convenience method that converts [self outputData] to a string, using UTF-8
 * encoding. You can call this before the task completes, but it's conceivable
 * that outputData ends in the middle of a multi-byte character, in which case
 * the UTF-8 conversion won't work properly. If you aren't expecting any
 * multi-byte characters you should be fine.
 */
- (NSString *)outputString;

/*!
 * Returns the NSTask's terminationStatus, which is 0 on success. Note that this
 * also returns 0 if the task hasn't launched or has launched but not completed.
 */
- (int)exitStatus;

@end
