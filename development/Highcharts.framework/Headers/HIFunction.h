/**
 * (c) 2009-2018 Highsoft AS
 *
 * License: www.highcharts.com/license
 * For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
 * In case of questions, please contact sales@highsoft.com
 */

#import <Foundation/Foundation.h>
#import "HIChartsJSONSerializable.h"
#import "HIChartContext.h"

/**
 */
@interface HIFunction : HIChartsJSONSerializable

/**
 *  Definition of an Objective-C/Swift closure.
 */
typedef void (^ HIClosure)(HIChartContext *);

/**
 *  A string representation of the JS function.
 */
@property(nonatomic, readwrite) NSString *jsFunction;

/**
 *  An Objective-C/Swift closure.
 */
@property (nonatomic) HIClosure closure;

/**
 *  An array of properties that will be available to get from the chart context.
 */
@property (nonatomic, strong) NSArray<NSString *> *properties;

/**
 *  Initializes with a javascript function.
 *  @param jsFunction A string representation of the JS function.
 */
- (instancetype)initWithJSFunction:(NSString *) jsFunction;

/**
 *  Initializes with a closure.
 *  @param closure The Objective-C/Swift closure.
 */
- (instancetype)initWithClosure:(HIClosure)closure;

/**
 *  Initializes with a closure and properties.
 *  @param closure The Objective-C/Swift closure.
 *  @param properties An array of the properties that will be available to get from the chart context.
 */
- (instancetype)initWithClosure:(HIClosure)closure properties:(NSArray<NSString *> *)properties;

/**
 *  Initializes with a closure and javascript function.
 *  @param closure The Objective-C/Swift closure.
 *  @param jsFunction A string representation of the JS function.
 */
- (instancetype)initWithClosure:(HIClosure)closure jsFunction:(NSString *)jsFunction;

/**
 *  Initializes with a closure, javascript function and properties.
 *  @param closure The Objective-C/Swift closure.
 *  @param jsFunction A string representation of the JS function.
 *  @param properties An array of the properties that will be available to get from the chart context.
 */
- (instancetype)initWithClosure:(HIClosure)closure jsFunction:(NSString *)jsFunction properties:(NSArray<NSString *> *)properties;

-(id)getFunction;

@end
