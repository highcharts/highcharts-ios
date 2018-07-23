/**
 * (c) 2009-2018 Highsoft AS
 *
 * License: www.highcharts.com/license
 * For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
 * In case of questions, please contact sales@highsoft.com
 */

#import <Foundation/Foundation.h>

/**
 *  The chart's context class. The class contains the current chart context that can be used in closures.
 */
@interface HIChartContext : NSObject <NSCopying>

-(instancetype)initWithContext:(NSDictionary *)context;

/**
 *  A method for getting chart's data depending on the actual context.
 *  @param param The property's name.
 *  @return The property value.
 */
- (id)getProperty:(NSString*)param;

@end
