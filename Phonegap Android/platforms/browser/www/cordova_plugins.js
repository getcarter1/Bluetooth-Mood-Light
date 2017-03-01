cordova.define('cordova/plugin_list', function(require, exports, module) {
module.exports = [
    {
        "file": "plugins/cordova-plugin-chrome-apps-common/events.js",
        "id": "cordova-plugin-chrome-apps-common.events",
        "pluginId": "cordova-plugin-chrome-apps-common",
        "clobbers": [
            "chrome.Event"
        ]
    },
    {
        "file": "plugins/cordova-plugin-chrome-apps-common/errors.js",
        "id": "cordova-plugin-chrome-apps-common.errors",
        "pluginId": "cordova-plugin-chrome-apps-common"
    },
    {
        "file": "plugins/cordova-plugin-chrome-apps-common/stubs.js",
        "id": "cordova-plugin-chrome-apps-common.stubs",
        "pluginId": "cordova-plugin-chrome-apps-common"
    },
    {
        "file": "plugins/cordova-plugin-chrome-apps-common/helpers.js",
        "id": "cordova-plugin-chrome-apps-common.helpers",
        "pluginId": "cordova-plugin-chrome-apps-common"
    },
    {
        "file": "plugins/cordova-plugin-chrome-apps-bluetooth/bluetooth.js",
        "id": "cordova-plugin-chrome-apps-bluetooth.bluetooth",
        "pluginId": "cordova-plugin-chrome-apps-bluetooth",
        "clobbers": [
            "chrome.bluetooth"
        ]
    },
    {
        "file": "plugins/cordova-plugin-ble-central/www/ble.js",
        "id": "cordova-plugin-ble-central.ble",
        "pluginId": "cordova-plugin-ble-central",
        "clobbers": [
            "ble"
        ]
    },
    {
        "file": "plugins/cordova-plugin-ble-central/src/browser/BLECentralPlugin.js",
        "id": "cordova-plugin-ble-central.BLECentralPlugin",
        "pluginId": "cordova-plugin-ble-central",
        "merges": [
            "ble"
        ]
    }
];
module.exports.metadata = 
// TOP OF METADATA
{
    "cordova-plugin-chrome-apps-common": "1.0.7",
    "cordova-plugin-chrome-apps-bluetooth": "1.1.5",
    "cordova-plugin-chrome-apps-bluetoothsocket": "1.0.1",
    "cordova-plugin-compat": "1.1.0",
    "cordova-plugin-ble-central": "1.1.4",
    "cordova-plugin-whitelist": "1.3.1"
}
// BOTTOM OF METADATA
});