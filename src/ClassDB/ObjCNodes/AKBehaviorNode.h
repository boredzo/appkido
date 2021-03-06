//
// AKBehaviorNode.h
//
// Created by Andy Lee on Sun Jun 30 2002.
// Copyright (c) 2003, 2004 Andy Lee. All rights reserved.
//

#import "AKDatabaseNode.h"

@class AKProtocolNode;
@class AKPropertyNode;
@class AKMethodNode;
@class AKCollectionOfNodes;

/*!
 * @class       AKBehaviorNode
 * @abstract    Abstract class that represents an Objective-C construct
 *              that can have methods.
 * @discussion  An AKBehaviorNode represents an Objective-C construct
 *              that can have methods -- i.e., a class, protocol, or
 *              category.
 */
@interface AKBehaviorNode : AKDatabaseNode
{
// [agl] put back @private -- really only need _indexOfInstanceMethods
//@private
    // Fully qualified path name of the .h file where my behavior is
    // declared.
    NSString *_headerFileWhereDeclared;

    // Contains AKProtocolNodes, one for each protocol my behavior
    // conforms to.
    NSMutableArray *_protocolNodes;

    // Indexes the contents of _protocolNodes.
    NSMutableSet *_protocolNodeNames;

    // Contains AKPropertyNodes, each representing a property of this class.
    AKCollectionOfNodes *_indexOfProperties;

    // Contains AKMethodNodes, one for each class method that has either
    // been found in my .h file or been found in the documentation for my
    // behavior.
    AKCollectionOfNodes *_indexOfClassMethods;

    // Contains AKMethodNodes, one for each instance method that has either
    // been found in my .h file or been found in the documentation for my
    // behavior.
    AKCollectionOfNodes *_indexOfInstanceMethods;

    // Contains names of all frameworks I belong to.  The first element
    // of the array is my primary framework.  Aside from that, the order
    // of the array is the order in which it was discovered that I belong
    // to the framework.
    NSMutableArray *_allOwningFrameworks;

    // Keys are names of frameworks I belong to.  Values are the
    // root file sections containing documentation specific to the
    // framework.
    NSMutableDictionary *_nodeDocumentationByFrameworkName;
}


#pragma mark -
#pragma mark Getters and setters -- general

/*!
 * @method      allOwningFrameworks
 * @discussion  Returned elements are instances of AKFramework.  The first
 *              one in the returned array is the node's -owningFramework.
 */
- (NSArray *)allOwningFrameworks;

- (BOOL)isClassNode;

// nb classes can have multiple header paths
- (NSString *)headerFileWhereDeclared;

- (void)setHeaderFileWhereDeclared:(NSString *)aPath;

- (void)addImplementedProtocol:(AKProtocolNode *)node;

/*!
 * @method      implementedProtocols
 * @discussion  Returns an array of zero or more AKProtocolNodes, one
 *              for each protocol implemented by my behavior, including
 *              protocols implemented via inheritance.
 */
- (NSArray *)implementedProtocols;

// frameworkName can be the main framework or an extra one
- (AKFileSection *)nodeDocumentationForFrameworkNamed:(NSString *)frameworkName;

- (void)setNodeDocumentation:(AKFileSection *)fileSection forFrameworkNamed:(NSString *)frameworkName;


#pragma mark -
#pragma mark Getters and setters -- properties

/** Returns only properties that are in this class's documentation. */
- (NSArray *)documentedProperties;

- (AKPropertyNode *)propertyNodeWithName:(NSString *)propertyName;

/*! Does nothing if a property with the same name already exists. */
- (void)addPropertyNode:(AKPropertyNode *)propertyNode;


#pragma mark -
#pragma mark Getters and setters -- class methods

/*!
 * Returns AKMethodNodes for class methods that have documentation
 * associated with them.  Does not include inherited methods.
 */
- (NSArray *)documentedClassMethods;

- (AKMethodNode *)classMethodWithName:(NSString *)methodName;

/*! Does nothing if a class method with the same name already exists. */
- (void)addClassMethod:(AKMethodNode *)methodNode;


#pragma mark -
#pragma mark Getters and setters -- instance methods

/*!
 * Returns AKMethodNodes for instance methods that have documentation
 * associated with them.  Does not include inherited methods.
 */
- (NSArray *)documentedInstanceMethods;

- (AKMethodNode *)instanceMethodWithName:(NSString *)methodName;

/*! Does nothing if an instance method with the same name already exists. */
- (void)addInstanceMethod:(AKMethodNode *)methodNode;


#pragma mark -
#pragma mark Getters and setters -- deprecated methods

/*!
 * We have to guess whether it's a class method or instance method,
 * because the docs lump all deprecated methods together.
 */
- (AKMethodNode *)addDeprecatedMethodIfAbsentWithName:(NSString *)methodName
    owningFramework:(AKFramework *)nodeOwningFW;

@end
