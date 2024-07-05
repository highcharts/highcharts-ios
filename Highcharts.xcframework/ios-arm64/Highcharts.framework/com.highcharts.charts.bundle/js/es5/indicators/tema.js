!/**
 * Highstock JS v11.4.5 (2024-07-04)
 *
 * Indicator series type for Highcharts Stock
 *
 * (c) 2010-2024 Rafal Sebestjanski
 *
 * License: www.highcharts.com/license
 */function(e){"object"==typeof module&&module.exports?(e.default=e,module.exports=e):"function"==typeof define&&define.amd?define("highcharts/indicators/tema",["highcharts","highcharts/modules/stock"],function(t){return e(t),e.Highcharts=t,e}):e("undefined"!=typeof Highcharts?Highcharts:void 0)}(function(e){"use strict";var t=e?e._modules:{};function o(t,o,r,n){t.hasOwnProperty(o)||(t[o]=n.apply(null,r),"function"==typeof CustomEvent&&e.win.dispatchEvent(new CustomEvent("HighchartsModuleLoaded",{detail:{path:o,module:t[o]}})))}o(t,"Stock/Indicators/TEMA/TEMAIndicator.js",[t["Core/Series/SeriesRegistry.js"],t["Core/Utilities.js"]],function(e,t){var o,r=this&&this.__extends||(o=function(e,t){return(o=Object.setPrototypeOf||({__proto__:[]})instanceof Array&&function(e,t){e.__proto__=t}||function(e,t){for(var o in t)Object.prototype.hasOwnProperty.call(t,o)&&(e[o]=t[o])})(e,t)},function(e,t){if("function"!=typeof t&&null!==t)throw TypeError("Class extends value "+String(t)+" is not a constructor or null");function r(){this.constructor=e}o(e,t),e.prototype=null===t?Object.create(t):(r.prototype=t.prototype,new r)}),n=e.seriesTypes.ema,l=t.correctFloat,i=t.isArray,s=t.merge,a=function(e){function t(){return null!==e&&e.apply(this,arguments)||this}return r(t,e),t.prototype.getEMA=function(t,o,r,n,l,i){return e.prototype.calculateEma.call(this,i||[],t,void 0===l?1:l,this.EMApercent,o,void 0===n?-1:n,r)},t.prototype.getTemaPoint=function(e,t,o,r){return[e[r-3],l(3*o.level1-3*o.level2+o.level3)]},t.prototype.getValues=function(t,o){var r,n,l,s,a=o.period,u=2*a,c=3*a,p=t.xData,h=t.yData,v=h?h.length:0,f=[],d=[],y=[],g=[],m=[],E={},A=-1,_=0,M=0;if(this.EMApercent=2/(a+1),!(v<3*a-2)){for(i(h[0])&&(A=o.index?o.index:0),M=(_=e.prototype.accumulatePeriodPoints.call(this,a,A,h))/a,_=0,l=a;l<v+3;l++)l<v+1&&(E.level1=this.getEMA(h,r,M,A,l)[1],g.push(E.level1)),r=E.level1,l<u?_+=E.level1:(l===u&&(M=_/a,_=0),E.level1=g[l-a-1],E.level2=this.getEMA([E.level1],n,M)[1],m.push(E.level2),n=E.level2,l<c?_+=E.level2:(l===c&&(M=_/a),l===v+1&&(E.level1=g[l-a-1],E.level2=this.getEMA([E.level1],n,M)[1],m.push(E.level2)),E.level1=g[l-a-2],E.level2=m[l-2*a-1],E.level3=this.getEMA([E.level2],E.prevLevel3,M)[1],(s=this.getTemaPoint(p,c,E,l))&&(f.push(s),d.push(s[0]),y.push(s[1])),E.prevLevel3=E.level3));return{values:f,xData:d,yData:y}}},t.defaultOptions=s(n.defaultOptions),t}(n);return e.registerSeriesType("tema",a),a}),o(t,"masters/indicators/tema.src.js",[t["Core/Globals.js"]],function(e){return e})});