/**
 * @license Highcharts JS v11.4.5 (2024-07-04)
 * @module highcharts/modules/exporting
 * @requires highcharts
 *
 * Exporting module
 *
 * (c) 2010-2024 Torstein Honsi
 *
 * License: www.highcharts.com/license
 */
'use strict';
import Highcharts from '../../Core/Globals.js';
import Exporting from '../../Extensions/Exporting/Exporting.js';
import HttpUtilities from '../../Core/HttpUtilities.js';
const G = Highcharts;
G.HttpUtilities = G.HttpUtilities || HttpUtilities;
G.ajax = G.HttpUtilities.ajax;
G.getJSON = G.HttpUtilities.getJSON;
G.post = G.HttpUtilities.post;
Exporting.compose(G.Chart, G.Renderer);
export default Highcharts;
