/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIPatternOptionsObject.h"
#import "HIAnimationOptionsObject.h"


/**
Holds a pattern definition.
*/
@interface HIPatternObject: HIChartsJSONSerializable

/**
Animation options for the image pattern loading.
*/
@property(nonatomic, readwrite) HIAnimationOptionsObject *animation;
/**
Pattern options
*/
@property(nonatomic, readwrite) HIPatternOptionsObject *pattern;
/**
Optionally an index referencing which pattern to use. Highcharts adds 10 default patterns to the `Highcharts.patterns` array. Additional pattern definitions can be pushed to this array if desired. This option is an index into this array.
*/
@property(nonatomic, readwrite) NSNumber *patternIndex;

-(NSDictionary *)getParams;

@end
