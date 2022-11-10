/**
* (c) 2009-2021 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIAttributes.h"


/**
Options for a _node_ label text which should follow marker's shape. **Note:** Only SVG-based renderer supports this option.
*/
@interface HITextPath: HIChartsJSONSerializable

@property(nonatomic, readwrite) HIAttributes *attributes;
/**
Enable or disable `textPath` option for link's or marker's data labels.

**Defaults to** `false`.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *enabled;

-(NSDictionary *)getParams;

@end
