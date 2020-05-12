/**
* (c) 2009-2020 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
Serialized form of an SVG definition, including children. Some key property names are reserved: tagName, textContent, and children.
*/
@interface HISVGDefinitionObject: HIChartsJSONSerializable

@property(nonatomic, readwrite) NSArray *children;
@property(nonatomic, readwrite) NSString *tagName;
@property(nonatomic, readwrite) NSString *textContent;

-(NSDictionary *)getParams;

@end
