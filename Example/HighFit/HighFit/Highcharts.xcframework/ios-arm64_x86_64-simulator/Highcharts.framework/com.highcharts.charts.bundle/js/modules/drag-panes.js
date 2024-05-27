!/**
 * Highstock JS v11.4.3 (2024-05-22)
 *
 * Drag-panes module
 *
 * (c) 2010-2024 Highsoft AS
 * Author: Kacper Madej
 *
 * License: www.highcharts.com/license
 */function(e){"object"==typeof module&&module.exports?(e.default=e,module.exports=e):"function"==typeof define&&define.amd?define("highcharts/modules/drag-panes",["highcharts","highcharts/modules/stock"],function(t){return e(t),e.Highcharts=t,e}):e("undefined"!=typeof Highcharts?Highcharts:void 0)}(function(e){"use strict";var t=e?e._modules:{};function s(e,t,s,i){e.hasOwnProperty(t)||(e[t]=i.apply(null,s),"function"==typeof CustomEvent&&window.dispatchEvent(new CustomEvent("HighchartsModuleLoaded",{detail:{path:t,module:e[t]}})))}s(t,"Extensions/DragPanes/AxisResizerDefaults.js",[],function(){return{minLength:"10%",maxLength:"100%",resize:{controlledAxis:{next:[],prev:[]},enabled:!1,cursor:"ns-resize",lineColor:"#cccccc",lineDashStyle:"Solid",lineWidth:4,x:0,y:0}}}),s(t,"Extensions/DragPanes/AxisResizer.js",[t["Extensions/DragPanes/AxisResizerDefaults.js"],t["Core/Utilities.js"]],function(e,t){let{addEvent:s,clamp:i,isNumber:o,relativeLength:n}=t;class r{constructor(e){this.init(e)}init(e,t){this.axis=e,this.options=e.options.resize||{},this.render(),t||this.addMouseEvents()}render(){let e=this.axis,t=e.chart,s=this.options,o=s.x||0,n=s.y,r=i(e.top+e.height+n,t.plotTop,t.plotTop+t.plotHeight),a={};t.styledMode||(a={cursor:s.cursor,stroke:s.lineColor,"stroke-width":s.lineWidth,dashstyle:s.lineDashStyle}),this.lastPos=r-n,this.controlLine||(this.controlLine=t.renderer.path().addClass("highcharts-axis-resizer")),this.controlLine.add(e.axisGroup);let h=t.styledMode?this.controlLine.strokeWidth():s.lineWidth;a.d=t.renderer.crispLine([["M",e.left+o,r],["L",e.left+e.width+o,r]],h),this.controlLine.attr(a)}addMouseEvents(){let e,t,i;let o=this,n=o.controlLine.element,r=o.axis.chart.container,a=[];o.mouseMoveHandler=e=e=>o.onMouseMove(e),o.mouseUpHandler=t=e=>o.onMouseUp(e),o.mouseDownHandler=i=()=>o.onMouseDown(),a.push(s(r,"mousemove",e),s(r.ownerDocument,"mouseup",t),s(n,"mousedown",i),s(r,"touchmove",e),s(r.ownerDocument,"touchend",t),s(n,"touchstart",i)),o.eventsToUnbind=a}onMouseMove(e){if(!e.touches||0!==e.touches[0].pageX){let t=this.axis.chart.pointer;this.grabbed&&t&&(this.hasDragged=!0,this.updateAxes(t.normalize(e).chartY-(this.options.y||0)))}}onMouseUp(e){let t=this.axis.chart.pointer;this.hasDragged&&t&&this.updateAxes(t.normalize(e).chartY-(this.options.y||0)),this.grabbed=this.hasDragged=this.axis.chart.activeResizer=void 0}onMouseDown(){this.axis.chart.pointer?.reset(!1,0),this.grabbed=this.axis.chart.activeResizer=!0}updateAxes(e){let t=this.axis.chart,s=this.options.controlledAxis,r=0===s.next.length?[t.yAxis.indexOf(this.axis)+1]:s.next,a=[this.axis].concat(s.prev),h=[],l=t.plotTop,c=t.plotHeight,d=l+c,u=e=>100*e/c+"%",p=(e,t,s)=>Math.round(i(e,t,s));e=i(e,l,d);let x=!1,f=e-this.lastPos;if(f*f<1)return;let g=!0;for(let s of[a,r])for(let i of s){let s,r;let a=o(i)?t.yAxis[i]:g?i:t.get(i),m=a&&a.options,y={};if(!m||m.isInternal){g=!1;continue}r=a.top;let z=Math.round(n(m.minLength||NaN,c)),v=Math.round(n(m.maxLength||NaN,c));if(g)(s=p(e-r,z,v))===v&&(x=!0),e=r+s,h.push({axis:a,options:{height:u(s)}});else{if(f=e-this.lastPos,s=p(a.len-f,z,v),(r=a.top+f)+s>d){let t=d-s-r;e+=t,r+=t}r<l&&(r=l)+s>d&&(s=c),s===z&&(x=!0),h.push({axis:a,options:{top:u(r-l),height:u(s)}})}g=!1,y.height=s}if(!x){for(let e of h)e.axis.update(e.options,!1);t.redraw(!1)}}destroy(){let e=this.axis;for(let t of(delete e.resizer,this.eventsToUnbind&&this.eventsToUnbind.forEach(e=>e()),this.controlLine.destroy(),Object.keys(this)))this[t]=null}}return r.resizerOptions=e,r}),s(t,"Extensions/DragPanes/DragPanes.js",[t["Extensions/DragPanes/AxisResizer.js"],t["Core/Defaults.js"],t["Core/Utilities.js"]],function(e,t,s){let{defaultOptions:i}=t,{addEvent:o,merge:n,wrap:r}=s;function a(){let t=this.resizer,s=this.options.resize;if(s){let i=!1!==s.enabled;t?i?t.init(this,!0):t.destroy():i&&(this.resizer=new e(this))}}function h(e){!e.keepEvents&&this.resizer&&this.resizer.destroy()}function l(e){this.chart.activeResizer||e.apply(this,[].slice.call(arguments,1))}function c(e){this.chart.activeResizer||e.apply(this,[].slice.call(arguments,1))}return{compose:function(t,s){t.keepProps.includes("resizer")||(n(!0,i.yAxis,e.resizerOptions),t.keepProps.push("resizer"),o(t,"afterRender",a),o(t,"destroy",h),r(s.prototype,"runPointActions",c),r(s.prototype,"drag",l))}}}),s(t,"masters/modules/drag-panes.src.js",[t["Core/Globals.js"],t["Extensions/DragPanes/AxisResizer.js"],t["Extensions/DragPanes/DragPanes.js"]],function(e,t,s){return e.AxisResizer=t,s.compose(e.Axis,e.Pointer),e})});