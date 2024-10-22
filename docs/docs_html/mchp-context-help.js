( function() {  var mapping = [{"appname":"", "appid":"USB_APPS_HOST_H3_USB_HOST_APP_EXAMPLES", "path":"GUID-4BEB4580-5653-4314-ABDE-36EF2BAAF53B.html"},{"appname":"", "appid":"USB_APPS_HOST_CDC_BASIC_EXAMPLE", "path":"GUID-33CDA167-6389-4F4C-8831-2962F864C071.html"},{"appname":"", "appid":"USB_APPS_HOST_CDC_MSD_EXAMPLE", "path":"GUID-56031831-AE5D-43EC-8A2A-29478E2C1377.html"},{"appname":"", "appid":"USB_APPS_HOST_HID_BASIC_KEYBOARD_EXAMPLE", "path":"GUID-561CCF33-8C3B-4A7F-A742-6FA7D15DBD0C.html"},{"appname":"", "appid":"USB_APPS_HOST_HID_BASIC_MOUSE_USART_EXAMPLE", "path":"GUID-BFB19243-0DD7-4764-9673-AE5E1971B659.html"},{"appname":"", "appid":"USB_APPS_HOST_HUB_CDC_HID_EXAMPLE", "path":"GUID-3EF64A8C-1650-42DE-90B7-4A1818495A29.html"},{"appname":"", "appid":"USB_APPS_HOST_HUB_MSD_EXAMPLE", "path":"GUID-B236DF72-8ED4-4ACF-B846-712BBB4090D2.html"},{"appname":"", "appid":"USB_APPS_HOST_MSD_BASIC_EXAMPLE", "path":"GUID-F9D5AB11-B9C2-4E37-A971-FC12A540E307.html"},{"appname":"", "appid":"USB_APPS_HOST_ROOT_HUB_DUAL_MSD_EXAMPLE", "path":"GUID-99CA2136-314F-430B-8F69-BB1A963654F5.html"},{"appname":"", "appid":"USB_APPS_HOST_VENDOR_EXAMPLE", "path":"GUID-B4D087ED-51B2-4F4A-9929-A4093E0E1083.html"}];
            var mchp = (function (mchp) {
                var mchp = mchp || {};
                var mapping = [];
        
                mchp.utils = {};
        
                mchp.utils.getQueryParam = function (name, url = window.location.href) {
                  name = name.replace(/[\[\]]/g, "\\$&");
                  var regex = new RegExp("[?&]" + name + "(=([^&#]*)|&|#|$)"),
                    results = regex.exec(url);
                  if (!results) return null;
                  if (!results[2]) return "";
                  return decodeURIComponent(results[2].replace(/\+/g, " "));
                };

                mchp.utils.isFirefox = typeof InstallTrigger !== 'undefined';
        
                mchp.init = function (options) {
                  mchp.mapping = options.mapping || [];
                  mchp.bindEvents();
                };
        
                mchp.bindEvents = function () {
                    if (mchp.utils.isFirefox) {
                      window.onload = mchp.checkRedirect;
                    } else {
                      document.onreadystatechange = mchp.checkRedirect;
                    }
                };

                mchp.checkRedirect = function() {
                  var contextId = mchp.utils.getQueryParam("contextId") || "";
                  if (contextId && contextId != undefined) {
                    var record = mchp.mapping.find(function(x){
                      return x.appid && x.appid.toLowerCase() == contextId.toLowerCase();
                    });
                    if (record && record.path) {
                      window.stop();
                      window.location = record.path;
                    }
                  }
                };
        
                return {
                  init: mchp.init,
                };
              })();
        
              mchp.init({
                mapping: mapping
              });

        })();