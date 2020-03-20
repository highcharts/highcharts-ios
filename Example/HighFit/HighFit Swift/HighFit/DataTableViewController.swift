//
//  DataTableViewController.swift
//  HighFit
//
//  License: www.highcharts.com/license
//  Copyright © 2020 Highsoft AS. All rights reserved.
//

import UIKit
import Highcharts

class DataTableViewController: UITableViewController, HIChartViewDelegate {
    
    @IBOutlet var toolbar: UIToolbar!
    @IBOutlet weak var segment: UISegmentedControl!
    
    var configuration: [String: Any]!
    
    var chartType: String!
    var data: [String : Any]!
    var chartViewBase: UIView!
    var chartView: HIChartView!
    
    var switchView: UISwitch!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        // Uncomment the following line to preserve selection between presentations
        // self.clearsSelectionOnViewWillAppear = false
        
        // Uncomment the following line to display an Edit button in the navigation bar for this view controller.
        // self.navigationItem.rightBarButtonItem = self.editButtonItem()
        
        self.chartType = (self.configuration["chartType"] as! String)
        
        self.tableView = UITableView(frame: self.view.bounds, style: .grouped)
        
        do {
            if let sourceName = self.configuration["source"] as? String,
                let sourcePath = Bundle.main.path(forResource: sourceName, ofType: "json"),
                let sourceData = try? Data(contentsOf: URL(fileURLWithPath: sourcePath)),
                let sourceJson = try JSONSerialization.jsonObject(with: sourceData) as? [String: Any] {
                self.data = sourceJson
            }
        } catch {
            print("Error deserializing JSON: \(error)")
        }
        
        self.title = self.configuration["title"] as? String
        
        self.tableView.tableHeaderView = self.toolbar
        
        self.tableView.tableFooterView = UIView(frame: CGRect.zero)
        
        self.segment.addTarget(self, action: #selector(self.actionSegment), for: .valueChanged)
        
        self.switchView = UISwitch()
        self.switchView.addTarget(self, action: #selector(self.actionSwitch), for: .valueChanged)
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        
        self.switchView.isOn = self.isSwitchOn()
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    // MARK: - Table view data source
    
    override func numberOfSections(in tableView: UITableView) -> Int {
        return 1
    }
    
    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return 3
    }
    
    override func tableView(_ tableView: UITableView, viewForHeaderInSection section: Int) -> UIView? {
        if self.chartViewBase == nil {
            self.chartViewBase = UIView(frame: CGRect(x: 0.0, y: 0.0, width: self.view.frame.size.width, height: 260.0))
            self.chartViewBase.backgroundColor = UIColor.white
            
            var tmpOptions = self.configuration!
            tmpOptions["exporting"] = true
            
            self.chartView = HIChartView(frame: CGRect(x: 5.0, y: 5.0, width: self.view.frame.size.width - 20, height: 240.0))
            self.chartView.delegate = self
            
            let series = self.data["day"] as! [Int]
            var sum: Int = 0
            for number in series {
                sum += number
            }
            
            tmpOptions["subtitle"] = "\(sum) \(tmpOptions["unit"]!)"
            
            self.chartView.options = OptionsProvider.provideOptions(forChartType: tmpOptions, series: series, type: "day")
            self.chartView.viewController = self
            
            self.chartViewBase.addSubview(self.chartView!)
        }
        return self.chartViewBase
    }
    
    override func tableView(_ tableView: UITableView, heightForHeaderInSection section: Int) -> CGFloat {
        return 260.0
    }
    
    
    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        var cell: UITableViewCell? = tableView.dequeueReusableCell(withIdentifier: "HighFitCellData")
        
        // Configure the cell...
        if cell == nil {
            cell = UITableViewCell(style: .default, reuseIdentifier: "HighFitCellData")
        }
        
        cell!.accessoryView = nil
        cell!.textLabel?.text = nil
        cell!.accessoryType = .none
        
        if indexPath.row == 0 {
            cell!.selectionStyle = .none
            cell!.textLabel?.text = "Show on Dashboard."
            
            cell!.accessoryView = self.switchView
        }
        
        if indexPath.row == 1 {
            cell!.accessoryType = .disclosureIndicator
            cell!.textLabel?.text = "Show all Data"
        }
        
        if indexPath.row == 2 {
            cell!.selectionStyle = .none
            cell!.textLabel?.text = "Unit"
            
            let label = UILabel()
            label.text = self.configuration["unit"] as? String
            label.font = UIFont.systemFont(ofSize: 16.0)
            label.textColor = UIColor.lightGray
            label.sizeToFit()
            cell!.accessoryView = label
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
    
    // MARK: - Table view delegate
    
    override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        tableView.deselectRow(at: indexPath, animated: true)
        
        if indexPath.row != 1 {
            return
        }
        
        let detailViewController = DataViewController(nibName: "DataViewController", bundle: nil)
        
        // Pass the selected object to the new view controller.
        detailViewController.unit = self.configuration["unit"] as? String
        detailViewController.data = (self.data["all"] as! [Any])
        
        // Push the view controller.
        self.navigationController?.pushViewController(detailViewController, animated: true)
    }
    
    /*
     // MARK: - Navigation
     
     // In a storyboard-based application, you will often want to do a little preparation before navigation
     override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
     // Get the new view controller using segue.destinationViewController.
     // Pass the selected object to the new view controller.
     }
     */
    
    // MARK: - Additional methods
    
    @objc func actionSwitch(_ actionSwitch: UISwitch) {
        // Show or hide chart on dashboard.
        if actionSwitch.isOn {
            DashboardViewController.sharedDashboard().dataSourceAdd(self.configuration)
        }
        else {
            DashboardViewController.sharedDashboard().dataSourceRem(self.configuration)
        }
    }
    
    @IBAction func actionSegment(_ sender: UISegmentedControl) {
        var dataName: String = "day"
        
        switch sender.selectedSegmentIndex {
        case 0:
            dataName = "day"
        case 1:
            dataName = "week"
        case 2:
            dataName = "month"
        case 3:
            dataName = "year"
        default:
            break
        }
        
        
        var tmpOptions = self.configuration!
        tmpOptions["exporting"] = true
        
        let series = self.data[dataName] as! [Int]
        var sum: Int = 0
        for number in series {
            sum += number
        }
        
        tmpOptions["subtitle"] = "\(sum) \(tmpOptions["unit"]!)"
        
        self.chartView.options = OptionsProvider.provideOptions(forChartType: tmpOptions, series: series, type: dataName)
    }
    
    private func isSwitchOn() -> Bool {
        let sources = UserDefaults.standard.value(forKey: "sources") as! [[String:Any]]
        for item in sources {
            if item["source"] as! String == self.configuration["source"] as! String {
                return true
            }
        }
        return false
    }
    
    //MARK: - HIChartViewDelegate
    
    func chartViewDidLoad(_ chart: HIChartView!) {
        print("Did load chart \(chart!)")
    }
    
}
