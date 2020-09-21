/**
* (c) 2009-2020 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
Accessibility options for an annotation label.

**Requires:**

* modules/accessibility
*/
@interface HILabelsAccessibility: HIChartsJSONSerializable

/**
Description of an annotation label for screen readers and other assistive technology.

**Defaults to** `undefined`.

**Requires:**

* modules/accessibility
*/
@property(nonatomic, readwrite) NSString *definition;

-(NSDictionary *)getParams;

@end
