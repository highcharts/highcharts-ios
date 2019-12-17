/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HISVGAttributes.h"


/**
Options for a label text which should follow marker's shape. Border and background are disabled for a label that follows a path. **Note:** Only SVG-based renderer supports this option. Setting `useHTML` to true will disable this option.
*/
@interface HITextPath: HIChartsJSONSerializable

/**
Presentation attributes for the text path.
*/
@property(nonatomic, readwrite) HISVGAttributes *attributes;
/**
Enable or disable `textPath` option for link's or marker's data labels.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *enabled;

-(NSDictionary *)getParams;

@end
