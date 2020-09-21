/**
* (c) 2009-2020 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
Represents the loose structure of a geographic JSON file.
*/
@interface HIGeoJSON: HIChartsJSONSerializable

/**
Full copyright note of the geographic data.
*/
@property(nonatomic, readwrite) NSString *copyright;
/**
Short copyright note of the geographic data suitable for watermarks.
*/
@property(nonatomic, readwrite) NSString *copyrightShort;
/**
Additional meta information based on the coordinate reference system.
*/
@property(nonatomic, readwrite) id crs;
/**
Data sets of geographic features.
*/
@property(nonatomic, readwrite) NSArray *features;
/**
Map projections and transformations to be used when calculating between lat/lon and chart values. Required for lat/lon support on maps. Allows resizing, rotating, and moving portions of a map within its projected coordinate system while still retaining lat/lon support. If using lat/lon on a portion of the map that does not match a `hitZone`, the definition with the key `default` is used.
*/
@property(nonatomic, readwrite) id hcTransform;
/**
Title of the geographic data.
*/
@property(nonatomic, readwrite) NSString *title;
/**
Type of the geographic data. Type of an optimized map collection is `FeatureCollection`.
*/
@property(nonatomic, readwrite) NSString *type;
/**
Version of the geographic data.
*/
@property(nonatomic, readwrite) NSString *version;

-(NSDictionary *)getParams;

@end
