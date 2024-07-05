!/**
 * Highstock JS v11.4.5 (2024-07-04)
 *
 * Indicator series type for Highcharts Stock
 *
 * (c) 2010-2024 Wojciech Chmiel
 *
 * License: www.highcharts.com/license
 */function(t){"object"==typeof module&&module.exports?(t.default=t,module.exports=t):"function"==typeof define&&define.amd?define("highcharts/indicators/apo",["highcharts","highcharts/modules/stock"],function(e){return t(e),t.Highcharts=e,t}):t("undefined"!=typeof Highcharts?Highcharts:void 0)}(function(t){"use strict";var e=t?t._modules:{};function o(e,o,r,n){e.hasOwnProperty(o)||(e[o]=n.apply(null,r),"function"==typeof CustomEvent&&t.win.dispatchEvent(new CustomEvent("HighchartsModuleLoaded",{detail:{path:o,module:e[o]}})))}o(e,"Stock/Indicators/APO/APOIndicator.js",[e["Core/Series/SeriesRegistry.js"],e["Core/Utilities.js"]],function(t,e){var o,r=this&&this.__extends||(o=function(t,e){return(o=Object.setPrototypeOf||({__proto__:[]})instanceof Array&&function(t,e){t.__proto__=e}||function(t,e){for(var o in e)Object.prototype.hasOwnProperty.call(e,o)&&(t[o]=e[o])})(t,e)},function(t,e){if("function"!=typeof e&&null!==e)throw TypeError("Class extends value "+String(e)+" is not a constructor or null");function r(){this.constructor=t}o(t,e),t.prototype=null===e?Object.create(e):(r.prototype=e.prototype,new r)}),n=t.seriesTypes.ema,i=e.extend,s=e.merge,a=e.error,u=function(t){function e(){return null!==t&&t.apply(this,arguments)||this}return r(e,t),e.prototype.getValues=function(e,o){var r,n,i=o.periods,s=o.index,u=[],p=[],c=[];if(2!==i.length||i[1]<=i[0]){a('Error: "APO requires two periods. Notice, first period should be lower than the second one."');return}var d=t.prototype.getValues.call(this,e,{index:s,period:i[0]}),l=t.prototype.getValues.call(this,e,{index:s,period:i[1]});if(d&&l){var f=i[1]-i[0];for(n=0;n<l.yData.length;n++)r=d.yData[n+f]-l.yData[n],u.push([l.xData[n],r]),p.push(l.xData[n]),c.push(r);return{values:u,xData:p,yData:c}}},e.defaultOptions=s(n.defaultOptions,{params:{period:void 0,periods:[10,20]}}),e}(n);return i(u.prototype,{nameBase:"APO",nameComponents:["periods"]}),t.registerSeriesType("apo",u),u}),o(e,"masters/indicators/apo.src.js",[e["Core/Globals.js"]],function(t){return t})});