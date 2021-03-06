/*
 * AKChildTopicOfFrameworkTopic.h
 *
 * Created by Andy Lee on Sat May 14 2005.
 * Copyright (c) 2005 Andy Lee. All rights reserved.
 */

#import "AKFrameworkTopic.h"

// intermediate class holding shared behavior of topics that are related to
// a framework topic; when a framework is selected in the browser, the
// next column is populated with instances of this
//
// subclasses reflect the type of framework and must implement:
//      -stringToDisplayInTopicBrowser
@interface AKChildTopicOfFrameworkTopic : AKFrameworkTopic
{
}

@end
