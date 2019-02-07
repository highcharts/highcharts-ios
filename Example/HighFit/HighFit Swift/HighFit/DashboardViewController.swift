//
//  DashboardViewController.swift
//  HighFit
//
//  License: www.highcharts.com/license
//  Copyright © 2019 Highsoft AS. All rights reserved.
//

import UIKit
import Highcharts

class DashboardViewController: UITableViewController, HIChartViewDelegate {
    
    var sources: [[String:Any]]!
    var data: [Any]!
    var dataName: String!
    var charts: [HIChartView]!
    
    private static let sharedInstance = DashboardViewController(nibName: nil, bundle: nil)
    
    public class func sharedDashboard() -> DashboardViewController {
        return sharedInstance
    }
    
    override init(nibName nibNameOrNil: String?, bundle nibBundleOrNil: Bundle?) {
        super.init(nibName: nibNameOrNil, bundle: nibBundleOrNil)
        
        self.title = "Dashboard"
        
        self.tabBarItem.image = UIImage(named: "ic_content_paste_white")
        
        self.loadSourcesAndData()
        
        self.tableView.rowHeight = 240.0
        
        self.tableView.tableHeaderView = UIView(frame: CGRect(x: 0.0, y: 0.0, width: self.tableView.bounds.size.width, height: 0.01))
        
        self.dataName = "day"
        
        self.tableView.tableHeaderView = nil
    }
    
    required init?(coder aDecoder: NSCoder) {
        super.init(coder: aDecoder)
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view from its nib.
        
        self.tableView.tableFooterView = UIView(frame: CGRect(x: 0, y: 0, width: self.view.frame.size.width, height: 8.0))
        
        self.tableView.separatorColor = UIColor.clear
        self.tableView.separatorInset = UIEdgeInsets.zero
    }
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        
        self.tableView.reloadData()
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    // MARK: - Table view data source
    
    override func tableView(_ tableView: UITableView, heightForRowAt indexPath: IndexPath) -> CGFloat {
        return 250.0
    }
    
    override func numberOfSections(in tableView: UITableView) -> Int {
        return 1
    }
    
    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return self.data.count
    }
    
    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        var options = self.sources[indexPath.row]
        
        let cellReuseIdentifier: String = options["chartType"] as! String
        
        var cell: UITableViewCell? = tableView.dequeueReusableCell(withIdentifier: cellReuseIdentifier)
        
        if cell == nil {
            cell = UITableViewCell(style: .default, reuseIdentifier: cellReuseIdentifier)
            
            cell!.selectionStyle = UITableViewCellSelectionStyle.none
            
            let chartView = HIChartView(frame: CGRect(x: 5.0, y: 5.0, width: self.view.bounds.size.width - 20, height: 240.0))
            chartView.backgroundColor = UIColor.clear
            chartView.delegate = self
            
            let seriesData = self.data[indexPath.row] as! [String: Any]
            let series = seriesData[self.dataName] as! [Int]
            var sum = 0
            for number in series {
                sum += number
            }
            
            options["subtitle"] = "\(sum) \(options["unit"]!)"
            
            chartView.options = OptionsProvider.provideOptions(forChartType: options, series: series, type: "day")
            
            cell!.addSubview(chartView)
            
            self.charts.append(chartView)
            
            let button = UIButton(type: .custom)
            button.setImage(UIImage(named: "ic_info_outline_white"), for: .normal)
            
            button.frame = CGRect(x: self.view.bounds.size.width - 20.0 - 5.0 - 24.0, y: 15.0, width: 24, height: 24)
            
            button.tag = indexPath.row
            button.addTarget(self, action: #selector(self.showDetailData), for: .touchUpInside)
            
            chartView.addSubview(button)
            
            return cell!
        }
        else {
            self.updateCellButtonTag(cell!, newIndex: indexPath.row)
        }
        
        return cell!
    }
    
    /*
     // Override to support conditional editing of the table view.
     override func tableView(_ tableView: UITableView, canEditRowAt indexPath: IndexPath) -> Bool {
     // Return false if you do not want the specified item to be editable.
     return true
     }
     */
    
    /*
     // Override to support editing the table view.
     override func tableView(_ tableView: UITableView, commit editingStyle: UITableViewCellEditingStyle, forRowAt indexPath: IndexPath) {
     if editingStyle == .delete {
     // Delete the row from the data source
     tableView.deleteRows(at: [indexPath], with: .fade)
     } else if editingStyle == .insert {
     // Create a new instance of the appropriate class, insert it into the array, and add a new row to the table view
     }
     }
     */
    
    /*
     // Override to support rearranging the table view.
     override func tableView(_ tableView: UITableView, moveRowAt fromIndexPath: IndexPath, to: IndexPath) {
     
     }
     */
    
    /*
     // Override to support conditional rearranging of the table view.
     override func tableView(_ tableView: UITableView, canMoveRowAt indexPath: IndexPath) -> Bool {
     // Return false if you do not want the item to be re-orderable.
     return true
     }
     */
    
    /*
     // MARK: - Navigation
     
     // In a storyboard-based application, you will often want to do a little preparation before navigation
     override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
     // Get the new view controller using segue.destinationViewController.
     // Pass the selected object to the new view controller.
     }
     */
    
    // MARK: - Additional methods
    
    func dataSourceAdd(_ dataSource: [String: Any]) {
        if !self.sources.contains(where: { $0["source"] as! String == dataSource["source"] as! String } ) {
            var tmp = self.sources!
            tmp.append(dataSource)
            self.sources = tmp
            
            UserDefaults.standard.setValue(self.sources, forKey: "sources")
        }
        
        self.loadSourcesAndData()
        self.tableView.reloadData()
    }
    
    func dataSourceRem(_ dataSource: [String: Any]) {
        if let index = self.sources.index(where: { $0["source"] as! String == dataSource["source"] as! String } ) {
            var tmp = self.sources!
            tmp.remove(at: index)
            self.sources = tmp
            
            UserDefaults.standard.setValue(self.sources, forKey: "sources")
        }
        
        self.loadSourcesAndData()
        self.tableView.reloadData()
    }
    
    private func updateCellButtonTag(_ cell: UITableViewCell, newIndex index: Int) {
        for view in cell.subviews {
            if view is HIChartView {
                for subview in view.subviews {
                    if subview is UIButton {
                        subview.tag = index
                    }
                }
            }
        }
    }
    
    private func loadSourcesAndData() {
        self.data = [Any]()
        
        self.charts = [HIChartView]()
        
        self.sources = UserDefaults.standard.value(forKey: "sources") as! [[String:Any]]
        
        var tmpData = [Any]()
        for source in self.sources {
            
            do {
                if let sourceName = source["source"] as? String,
                    let sourcePath = Bundle.main.path(forResource: sourceName, ofType: "json"),
                    let sourceData = try? Data(contentsOf: URL(fileURLWithPath: sourcePath)),
                    let sourceJson = try JSONSerialization.jsonObject(with: sourceData) as? [String: Any] {
                    tmpData.append(sourceJson)
                }
            } catch {
                print("Error deserializing JSON: \(error)")
            }
        }
        self.data = tmpData
    }
    
    @objc func showDetailData(_ sender: UIButton) {
        self.tabBarController?.selectedIndex = 1
        
        let dataView = DataTableViewController(nibName: "DataTableViewController", bundle: nil)
        
        // Pass the selected object to the new view controller.
        
        let options = self.sources[sender.tag]
        dataView.configuration = options
        
        let navController = self.tabBarController?.selectedViewController as? UINavigationController
        
        if navController?.visibleViewController is DataTableViewController {
            navController?.popViewController(animated: false)
        }
        
        navController?.pushViewController(dataView, animated: true)
    }
    
    // MARK: - HIGChartViewDelegate
    
    func chartViewDidLoad(_ chart: HIChartView!) {
        print("Did load chart \(chart!)")
    }
    
}
