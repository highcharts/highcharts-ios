!/**
 * Highcharts JS v11.4.5 (2024-07-04)
 *
 * (c) 2009-2024 Sebastian Bochan, Rafal Sebestjanski
 *
 * License: www.highcharts.com/license
 */function(t){"object"==typeof module&&module.exports?(t.default=t,module.exports=t):"function"==typeof define&&define.amd?define("highcharts/modules/dumbbell",["highcharts"],function(o){return t(o),t.Highcharts=o,t}):t("undefined"!=typeof Highcharts?Highcharts:void 0)}(function(t){"use strict";var o=t?t._modules:{};function e(o,e,r,i){o.hasOwnProperty(e)||(o[e]=i.apply(null,r),"function"==typeof CustomEvent&&t.win.dispatchEvent(new CustomEvent("HighchartsModuleLoaded",{detail:{path:e,module:o[e]}})))}e(o,"Series/AreaRange/AreaRangePoint.js",[o["Core/Series/SeriesRegistry.js"],o["Core/Utilities.js"]],function(t,o){var e,r=this&&this.__extends||(e=function(t,o){return(e=Object.setPrototypeOf||({__proto__:[]})instanceof Array&&function(t,o){t.__proto__=o}||function(t,o){for(var e in o)Object.prototype.hasOwnProperty.call(o,e)&&(t[e]=o[e])})(t,o)},function(t,o){if("function"!=typeof o&&null!==o)throw TypeError("Class extends value "+String(o)+" is not a constructor or null");function r(){this.constructor=t}e(t,o),t.prototype=null===o?Object.create(o):(r.prototype=o.prototype,new r)}),i=t.seriesTypes.area.prototype,s=i.pointClass,n=i.pointClass.prototype,l=o.defined,p=o.isNumber;return function(t){function o(){return null!==t&&t.apply(this,arguments)||this}return r(o,t),o.prototype.setState=function(){var t=this.state,o=this.series,e=o.chart.polar;l(this.plotHigh)||(this.plotHigh=o.yAxis.toPixels(this.high,!0)),l(this.plotLow)||(this.plotLow=this.plotY=o.yAxis.toPixels(this.low,!0)),o.lowerStateMarkerGraphic=o.stateMarkerGraphic,o.stateMarkerGraphic=o.upperStateMarkerGraphic,this.graphic=this.graphics&&this.graphics[1],this.plotY=this.plotHigh,e&&p(this.plotHighX)&&(this.plotX=this.plotHighX),n.setState.apply(this,arguments),this.state=t,this.plotY=this.plotLow,this.graphic=this.graphics&&this.graphics[0],e&&p(this.plotLowX)&&(this.plotX=this.plotLowX),o.upperStateMarkerGraphic=o.stateMarkerGraphic,o.stateMarkerGraphic=o.lowerStateMarkerGraphic,o.lowerStateMarkerGraphic=void 0;var r=o.modifyMarkerSettings();n.setState.apply(this,arguments),o.restoreMarkerSettings(r)},o.prototype.haloPath=function(){var t=this.series.chart.polar,o=[];return this.plotY=this.plotLow,t&&p(this.plotLowX)&&(this.plotX=this.plotLowX),this.isInside&&(o=n.haloPath.apply(this,arguments)),this.plotY=this.plotHigh,t&&p(this.plotHighX)&&(this.plotX=this.plotHighX),this.isTopInside&&(o=o.concat(n.haloPath.apply(this,arguments))),o},o.prototype.isValid=function(){return p(this.low)&&p(this.high)},o}(s)}),e(o,"Series/Dumbbell/DumbbellPoint.js",[o["Series/AreaRange/AreaRangePoint.js"],o["Core/Utilities.js"]],function(t,o){var e,r=this&&this.__extends||(e=function(t,o){return(e=Object.setPrototypeOf||({__proto__:[]})instanceof Array&&function(t,o){t.__proto__=o}||function(t,o){for(var e in o)Object.prototype.hasOwnProperty.call(o,e)&&(t[e]=o[e])})(t,o)},function(t,o){if("function"!=typeof o&&null!==o)throw TypeError("Class extends value "+String(o)+" is not a constructor or null");function r(){this.constructor=t}e(t,o),t.prototype=null===o?Object.create(o):(r.prototype=o.prototype,new r)}),i=o.extend,s=o.pick,n=function(t){function o(){return null!==t&&t.apply(this,arguments)||this}return r(o,t),o.prototype.setState=function(){var t,o,e,r=this.series,n=r.chart,l=r.options.lowColor,p=r.options.marker,a=r.options.lowMarker,h=this.options,c=h.lowColor,u=this.zone&&this.zone.color,d=s(c,null==a?void 0:a.fillColor,l,h.color,u,this.color,r.color),y="attr";if(this.pointSetState.apply(this,arguments),!this.state){y="animate";var f=this.graphics||[],g=f[0],v=f[1];g&&!n.styledMode&&(g.attr({fill:d}),v&&(e={y:this.y,zone:this.zone},this.y=this.high,this.zone=this.zone?this.getZone():void 0,o=s(this.marker?this.marker.fillColor:void 0,p?p.fillColor:void 0,h.color,this.zone?this.zone.color:void 0,this.color),v.attr({fill:o}),i(this,e)))}null===(t=this.connector)||void 0===t||t[y](r.getConnectorAttribs(this))},o.prototype.destroy=function(){return this.graphic||(this.graphic=this.connector,this.connector=void 0),t.prototype.destroy.call(this)},o}(t);return i(n.prototype,{pointSetState:t.prototype.setState}),n}),e(o,"Series/Dumbbell/DumbbellSeriesDefaults.js",[],function(){return{trackByArea:!1,fillColor:"none",lineWidth:0,pointRange:1,connectorWidth:1,stickyTracking:!1,groupPadding:.2,crisp:!1,pointPadding:.1,legendSymbol:"rectangle",lowColor:"#333333",states:{hover:{lineWidthPlus:0,connectorWidthPlus:1,halo:!1}}}}),e(o,"Series/Dumbbell/DumbbellSeries.js",[o["Series/Dumbbell/DumbbellPoint.js"],o["Series/Dumbbell/DumbbellSeriesDefaults.js"],o["Core/Globals.js"],o["Core/Series/SeriesRegistry.js"],o["Core/Renderer/SVG/SVGRenderer.js"],o["Core/Utilities.js"]],function(t,o,e,r,i,s){var n,l=this&&this.__extends||(n=function(t,o){return(n=Object.setPrototypeOf||({__proto__:[]})instanceof Array&&function(t,o){t.__proto__=o}||function(t,o){for(var e in o)Object.prototype.hasOwnProperty.call(o,e)&&(t[e]=o[e])})(t,o)},function(t,o){if("function"!=typeof o&&null!==o)throw TypeError("Class extends value "+String(o)+" is not a constructor or null");function e(){this.constructor=t}n(t,o),t.prototype=null===o?Object.create(o):(e.prototype=o.prototype,new e)}),p=e.noop,a=r.seriesTypes,h=a.arearange,c=a.column,u=a.columnrange,d=s.extend,y=s.merge,f=s.pick,g=function(t){function e(){return null!==t&&t.apply(this,arguments)||this}return l(e,t),e.prototype.getConnectorAttribs=function(t){var o,e=this.chart,r=t.options,s=this.options,n=this.xAxis,l=this.yAxis,p=f(s.states&&s.states.hover&&s.states.hover.connectorWidthPlus,1),a=f(r.dashStyle,s.dashStyle),h=l.toPixels(s.threshold||0,!0),c=e.inverted?l.len-h:h,u=f(r.connectorWidth,s.connectorWidth),y=f(r.connectorColor,s.connectorColor,r.color,t.zone?t.zone.color:void 0,t.color),g=f(t.plotLow,t.plotY),v=f(t.plotHigh,c);if("number"!=typeof g)return{};t.state&&(u+=p),g<0?g=0:g>=l.len&&(g=l.len),v<0?v=0:v>=l.len&&(v=l.len),(t.plotX<0||t.plotX>n.len)&&(u=0),t.graphics&&t.graphics[1]&&(o={y:t.y,zone:t.zone},t.y=t.high,t.zone=t.zone?t.getZone():void 0,y=f(r.connectorColor,s.connectorColor,r.color,t.zone?t.zone.color:void 0,t.color),d(t,o));var b={d:i.prototype.crispLine([["M",t.plotX,g],["L",t.plotX,v]],u)};return!e.styledMode&&(b.stroke=y,b["stroke-width"]=u,a&&(b.dashstyle=a)),b},e.prototype.drawConnector=function(t){var o=f(this.options.animationLimit,250),e=t.connector&&this.chart.pointCount<o?"animate":"attr";t.connector||(t.connector=this.chart.renderer.path().addClass("highcharts-lollipop-stem").attr({zIndex:-1}).add(this.group)),t.connector[e](this.getConnectorAttribs(t))},e.prototype.getColumnMetrics=function(){var t=c.prototype.getColumnMetrics.apply(this,arguments);return t.offset+=t.width/2,t},e.prototype.translate=function(){var t=this.chart.inverted;this.setShapeArgs.apply(this),this.translatePoint.apply(this,arguments);for(var o=0,e=this.points;o<e.length;o++){var r=e[o],i=r.pointWidth,s=r.shapeArgs,n=void 0===s?{}:s,l=r.tooltipPos;r.plotX=n.x||0,n.x=r.plotX-i/2,l&&(t?l[1]=this.xAxis.len-r.plotX:l[0]=r.plotX)}this.columnMetrics.offset-=this.columnMetrics.width/2},e.prototype.drawPoints=function(){var t,o,e,r,i=this.chart,s=this.points.length,n=this.lowColor=this.options.lowColor,l=this.options.lowMarker,p=0;for(this.seriesDrawPoints.apply(this,arguments);p<s;){var a=(e=this.points[p]).graphics||[],h=a[0],c=a[1];this.drawConnector(e),c&&(c.element.point=e,c.addClass("highcharts-lollipop-high")),(null===(t=e.connector)||void 0===t?void 0:t.element).point=e,h&&(r=e.zone&&e.zone.color,o=f(e.options.lowColor,null==l?void 0:l.fillColor,n,e.options.color,r,e.color,this.color),i.styledMode||h.attr({fill:o}),h.addClass("highcharts-lollipop-low")),p++}},e.prototype.pointAttribs=function(o,e){var r=t.prototype.pointAttribs.apply(this,arguments);return"hover"===e&&delete r.fill,r},e.prototype.setShapeArgs=function(){c.prototype.translate.apply(this),u.prototype.afterColumnTranslate.apply(this)},e.defaultOptions=y(h.defaultOptions,o),e}(h);return d(g.prototype,{crispCol:c.prototype.crispCol,drawGraph:p,drawTracker:c.prototype.drawTracker,pointClass:t,seriesDrawPoints:h.prototype.drawPoints,trackerGroups:["group","markerGroup","dataLabelsGroup"],translatePoint:h.prototype.translate}),r.registerSeriesType("dumbbell",g),g}),e(o,"masters/modules/dumbbell.src.js",[o["Core/Globals.js"]],function(t){return t})});