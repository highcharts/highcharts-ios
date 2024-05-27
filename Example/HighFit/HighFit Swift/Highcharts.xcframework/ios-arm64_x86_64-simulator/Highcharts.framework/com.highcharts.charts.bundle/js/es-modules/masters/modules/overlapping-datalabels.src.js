/**
 * @license Highcharts JS v11.4.3 (2024-05-22)
 * @module highcharts/modules/overlapping-datalabels
 * @requires highcharts
 *
 * (c) 2009-2024 Torstein Honsi
 *
 * License: www.highcharts.com/license
 */
'use strict';
import Highcharts from '../../Core/Globals.js';
import OverlappingDataLabels from '../../Extensions/OverlappingDataLabels.js';
const G = Highcharts;
G.OverlappingDataLabels = G.OverlappingDataLabels || OverlappingDataLabels;
G.OverlappingDataLabels.compose(G.Chart);
export default Highcharts;
