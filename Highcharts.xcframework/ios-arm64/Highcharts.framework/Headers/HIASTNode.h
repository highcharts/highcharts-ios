/**
* (c) 2009-2021 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HISVGAttributes.h"


/**
Serialized form of an SVG/HTML definition, including children.
*/
@interface HIASTNode: HIChartsJSONSerializable

@property(nonatomic, readwrite) HISVGAttributes *attributes;
@property(nonatomic, readwrite) NSArray *children;
@property(nonatomic, readwrite) NSString *tagName;
@property(nonatomic, readwrite) NSString *textContent;

-(NSDictionary *)getParams;

@end
