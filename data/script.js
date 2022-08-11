let lockImage = "data:image/png;base64,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";
let unlockImage = " data:image/png;base64,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";
let signal0 = " data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAADwAAAA8CAQAAACQ9RH5AAAABGdBTUEAALGPC/xhBQAAACBjSFJNAAB6JgAAgIQAAPoAAACA6AAAdTAAAOpgAAA6mAAAF3CculE8AAAAAmJLR0QA/4ePzL8AAAAJcEhZcwAAZZQAAGWUAe4tZ2YAAAAHdElNRQfmCAQHEioV2yEpAAACVElEQVRYw+2ZTWsTURSGn3snqRPbClJ1JW5cqLgQPxChuLA7Ny7EfyDYjaDgzrWC6Kr+APEP9E/4QRFRQV0IUhCVqmBV8GvSzMx1MWfunSQIIt6TYvoOuXmZTPLMuedmMjnHUOs48xxmKyltEiwGAzJWCu73co1nJ1tJTo+ffOQJt7lDGQ6f5BJv/IExtxUuMx2wC/RUsA5Hzk02V+ALiliHY43zYDjAIrsl9nfc5S0ZPXJKSkqcZKuZZ9Nw9WiGvMViSGiRMEHKDAfZKZ+yzBm47s9kiWO0/mAB/Y0MExxlybMW4J7YVeYiQYPm+Cy0h7As9j5booN38Exory1TsvMTWXRwl2/iJi2bxGbNL3YkFXTFtS1tsb3G2o0H7olrWazfGR/sKMTZAI4/0QPg+tJfqkRch2cCOD62Cm8IrCHnwxtZxGiDGxFrKkw1umBGB/bSXdXrK8e6q3qUOdbVRsT/e8RjfskcE/DGVKtpPU21zg1BI2Kd3+GhExibS6bXqMAu5Fj3bnNcIg4l2ZFNdQOs85+iTm0fWEO+4mJ9OSRRiNiEGpMlF9tWAddVtdz6kldKEh2c0BGXWb6L3UYaHZwyI+6r5b3YfcxGB8+yV9wK3JA6vOMpJ+n09V3+nSzTnOK578tcMexnkT3y8hce8IGcgoLCNwfqh2s0CgZbBgCur1VUbQkJLVKm2MUh3395wWmAebqqzZCMcxW/wzVFdMbVsIw7XOSVCvYl8xU2ZOUIZznBdlISEt/OqY9wfbnsd4Oj82O1OgoK1vjBKo+4xePqrb8A8x4GNYaYc3QAAAAldEVYdGRhdGU6Y3JlYXRlADIwMjItMDgtMDRUMDc6MTg6MjArMDA6MDASU2BhAAAAJXRFWHRkYXRlOm1vZGlmeQAyMDIyLTA4LTA0VDA3OjE4OjIwKzAwOjAwYw7Y3QAAABl0RVh0U29mdHdhcmUAd3d3Lmlua3NjYXBlLm9yZ5vuPBoAAAAASUVORK5CYII=";
let signal1 = " data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAADwAAAA8CAQAAACQ9RH5AAAABGdBTUEAALGPC/xhBQAAACBjSFJNAAB6JgAAgIQAAPoAAACA6AAAdTAAAOpgAAA6mAAAF3CculE8AAAAAmJLR0QA/4ePzL8AAAAJcEhZcwAAZZQAAGWUAe4tZ2YAAAAHdElNRQfmCAQHEioV2yEpAAACyklEQVRYw+2Zz2sTQRTHPzObtIltBAl6kh4qVMWDv4oIxYO9efEgHnsTzEVQ8JazguipHjyJ9A9I77304g+KiD9QDxUp2CpVi1Vp/ZE0uzsednZ20yBmV3dSbN+SyXc3u/nsm/cySd4ThHaCCkfZQYE8DhKBAD0GFqnfm4o9K735uDT5ySeeMsFd/Oj0Pi7z1pyY5bZIlVKEHadpBatQuNxkWwC+aBGrUKxxAQQHmWSP9v0993hHnSYuPj4+SkcrHmcRU+Eo2rREInDI4dBDgTKH2a3fZY6zcN3cyQzHyXWQQGlM0MMxZgxrHO5rucxoRtDIRvmiaY9gTssHbM8cvIsXmrYg6dcHP1PPHNzgm1Z9kl4t6/EPdkbm0dAqL8lr2YzlbnbgplY5iTQHswcrPK1kBM5+oteBw6Xft+Jx6J6IwNljA/fawDZMGfe65jG2wTGPbVo01dgF0z2wMbtZvbFibDeruxlju7bl8f/u8SZfMjcJeGuqrdlGmmo7PwhiHtv5Hm67gfSlhxIDwAKrifz96xiPUmOaaWrpCxi+Lg7cThDlYVPAUMwx3PF1ggl9lRfFOElyjTFo9CBjafxNM9W9DLXsD5lyRuem0njcZKllf8kUGP5kUUk2FdinxorZW6GWopoQAyf5TzFFlXk8POapMpUAGIZW5WLgzs3lFtMcAp7xKtESZCouOVMOcRLltWKW2QTnByaiGpPE1TJvYbUWpqrmSpORRZzMwQ5FreqS71qWKWQOLlDWalXyQcv9jGQOHmGfVotww6zWzzlFsaXv8u9MUuI0L01f5orgAJPs1S9/5SEfcfHw8ExzIHyoWKNgfcsAQLW0ioLNwSFHgX4GOGL6L7OcAajQsNoMqXM+4Be5ZhFd52qUxkUu8cYK9jWVABtFZZhznGQnBRwc084Jz1AtsWxV60dlxiA7PDzW+MEyj7nDk+DSX1fcMi8hI3C3AAAAJXRFWHRkYXRlOmNyZWF0ZQAyMDIyLTA4LTA0VDA3OjE4OjIwKzAwOjAwElNgYQAAACV0RVh0ZGF0ZTptb2RpZnkAMjAyMi0wOC0wNFQwNzoxODoyMCswMDowMGMO2N0AAAAZdEVYdFNvZnR3YXJlAHd3dy5pbmtzY2FwZS5vcmeb7jwaAAAAAElFTkSuQmCC";
let signal2 = " data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAADwAAAA8CAQAAACQ9RH5AAAABGdBTUEAALGPC/xhBQAAACBjSFJNAAB6JgAAgIQAAPoAAACA6AAAdTAAAOpgAAA6mAAAF3CculE8AAAAAmJLR0QA/4ePzL8AAAAJcEhZcwAAZZQAAGWUAe4tZ2YAAAAHdElNRQfmCAQHEiti3BG/AAADd0lEQVRYw+2ZS2gTURRAz7xJamJbPxTFhRZUqEoX/lIRiot2obgRFJfuBLMRKuiqGzcWRDfWhQsVqZ9l2o0LRezCH0XqJ6hIRQq2Sv1WSz+aNpk8F3nzZtIqnZk6UxHvkMmdl3k5c+feTN6918CWHaTZylISxDERGBig9iVxtN+LdL1LtRUpkOcHX3hKB3cpOqdXcpS3+sQwtyFaqXaw7eQjwUokBc6ysARuiRArkUxxGAw20slaZft77vGOHHkKFClSRCpvuf1suDR7b8zQBQIDkxgmFSSoYTMr1bf0sx9O6SvpYTsxDwEURAwq2EaPZrXDfaUO0xwS1JFmvilaL/Qr9QGLQgcv57miDQqq1OBXcqGDJxlXWqVggVJz7h92SGIxqbS4IK7UvCt2wwPnlRYTCD0YPlhiKU044PBv9DSw/egvRmKxbZ7hgMPHlsybAY5CpDZv3iwmarDL4ijFudVEC2b+wFqijeq/y8fRRvV8+jha+W/xv26x6+cUdAGfYAlVCCb4xndf6MDgJCl2kmIVizGYYIBebvGIiSDmSyQXPDw8BU106WzA2Ua4zi5MD/Ov6Tk+wEs5zuff5oBfaaNmVvDVIOCWWRPQY97BfqL6DlnX0RQjjDDlGsly2/uX+QmuLGnOsxF4SRe9fABW0MBe6oFnpMsu7Nci3ar34IIGbtDO6rKx1ZzhBg0eZguuzPTxRY9LgiqdbTkS1znnbODLNi+G9LkGGf/FWF4nY15FBi89VFMLDDLmBzf3P4lmMnTTTSZ4AaPo08cAKV3AkPST8jzPoEPNsoSz7vNxsQdYo/U1HAhib5BbvYC6suM6Xc7wLjKIxXk+lR1/8hzTTkk2ELhIhlF9NEomQDXBBfaTU9yklQEsLAZo5aYPoO1aGXOBvUuBc3SzCcjyylcqoCsuMV0OMX3FtaSPPh/nl8RwakyCglLjEaRvhn7OF4SOyKSHpctcxSSptJzQi7QaEqGDE3pxNCb4oNQNNIYObmS90obgtH5aP2M3ybK+y58TQTV7eIHdlzlhUE8n69THIzzkIwUsLCzdHLBf0tUomN4yAMr+2e0GgYlJjARV1LJF91/62AeQZjLSZkiOQyV+kpMRonO0OWGc5AhvIsG+Jl3COl5JcZAmlpHAxNTtHPsMWebLcm36Xup9KTosLKb4zjCPucST0tSfkO+oGeRNtu4AAAAldEVYdGRhdGU6Y3JlYXRlADIwMjItMDgtMDRUMDc6MTg6MjArMDA6MDASU2BhAAAAJXRFWHRkYXRlOm1vZGlmeQAyMDIyLTA4LTA0VDA3OjE4OjIwKzAwOjAwYw7Y3QAAABl0RVh0U29mdHdhcmUAd3d3Lmlua3NjYXBlLm9yZ5vuPBoAAAAASUVORK5CYII=";
let signal3 = " data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAADwAAAA8CAQAAACQ9RH5AAAABGdBTUEAALGPC/xhBQAAACBjSFJNAAB6JgAAgIQAAPoAAACA6AAAdTAAAOpgAAA6mAAAF3CculE8AAAAAmJLR0QA/4ePzL8AAAAJcEhZcwAAZZQAAGWUAe4tZ2YAAAAHdElNRQfmCAQHEiti3BG/AAAEgElEQVRYw8WZT2wUVRzHPzOz2+5KiylNCQYhaTEF00OpbBsN8dDGaLxoNBzxhNDEGDFKNKkHDtLE6MV68KDG4B/QQ0ETD6ChifiHiq1rg4bUYBNbFSgCNm0p+2dmnod9+2ZmO7s7szDr92VnfzPvzfvO7/1+897v90ajiAcZZActJIhjoKOhgTwW4EjlIVz/QhYbkzw3ucrPHOYbbKf5Gl7kT9UwynKRIZod2hHydaEVCEze4o4C8f460goEOZ4FjW6OsUXqfolv+YsMeUxsbGyEtJbbzppLKh61VbKOjoZBDIMGErTSw92ylxl2wevqSca5n1gAB6oFGg30Ma64RuA7KV5jICJSBwP8K9kmYEaK37M2cuL1/CLZ5nSa5MXrZCInzrIspTU6jVLMuF/siGCRlVJcJy7FvMt3oyPOSymmo6uL0RMLLCnpDnH0A11CXJz67bpoXFRPc4ijpy2ot4q4HhBKvf9NY+pN7NK4nnCGmvoSu8a1tmWwkTiG7MjGJBveULFQXh2nnT766GAtcTTAxmSFOX7kDL+TC6yxFlzjNh7icR5go9TViz1c4gyfMcaVirTCeyIQvFtB93XsZZxcgGjqLE/TUrYfg09V26rEGgOcChEO5vmS/jJ9hSBu4mXmfYPUFZZYJoPlUzvPSyrA8BJ/UmxT2cZ3McxTJZ7/N2kmucBVsugkaaWDHrazyWX79QyzlVe4XKnzSho/VzKIP/ACXSpmcdDAFvZyusQLDvhofDTYUHcxqeqneYa2iuOzjn2cV+3TdPsQHwlq4x2kEZgcYRtBsI2jmAjS9PrU6sGJIcXXvOokWhIJNnAPnWws5kEKzRzkc3p8+9L5OJhzAUyyi0XXnJQkxcOk2MSdaNxglgm+YpIbsn6JQzRws/rgBJlAnCfu57jKBpyywBc84jujldU4DHELB/mn7MRxnWFaqxJ/VAvx/qqz1oHgxGHW49NMuc5yLLDgWY+mOBW8szDr8RSDvEM3cJ7jTHAZ2EAvT9AFnGPQ82D+CLk6OejlBCO0e6618yYnfN/bUuh8uNrG7wUMCZpUtuUg7rsk+BF/4LzHImRkvexzLa+SsaAIMIGUQzObgTmWwtDdepQ5wChjjDFa+waGHdLGACm1gSGYIRX4Po3D8i5Ld+K+EA+7mw4ld7C7Fn1rGepGOj3nnT6hQTWIWjTOl4SwVwL7tLMlWxOxzSiL6myR0Rp2E1zEYTLlkwwxi4XFLEOcDEFYNK2IuYiDw+RtxtgOTPFbqLxJ7bjE1HaIEcqvBdNMh2hfgObsMemYUozXYVNCU/O8qSuPTAYIXW4VBkkpZXQVpLWSiJw4oYKjJV2lGfeyM3LinSo6vwhvqNn6HI+S9Hx3uX3QaeYxfpVMNoc0ujjGVlm9wFnmMbGwsNTHgeJPRg4UP+2U7hQJz6eiQjEwiJGgic3cp9KCaZ4EGCQbOPu9HSXDvgJ/ktfqSJ1h2HHjJM/zR11oLzBYoHWskmIP/bSRwMBQn3OKLYTHll6p9CjUseAdFhY5VrjGT7xPunDrf++rb9WQOZ8UAAAAJXRFWHRkYXRlOmNyZWF0ZQAyMDIyLTA4LTA0VDA3OjE4OjIwKzAwOjAwElNgYQAAACV0RVh0ZGF0ZTptb2RpZnkAMjAyMi0wOC0wNFQwNzoxODoyMCswMDowMGMO2N0AAAAZdEVYdFNvZnR3YXJlAHd3dy5pbmtzY2FwZS5vcmeb7jwaAAAAAElFTkSuQmCC";
let signal4 = " data:image/png;base64,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";

function checkSearch() {
    wifi_box = document.getElementById("wifi_box");
    loader = document.getElementById("loading");
    var xhr = new XMLHttpRequest();
    xhr.onreadystatechange = function () {
        if (this.readyState == 4 && this.status == 200) {
            resp = this.responseText;
            if (resp == "scanning") {
                if (!loader.classList.contains("loadingOn")) {
                    loader.classList.add("loadingOn");
                }
            } else {
                if (loader.classList.contains("loadingOn")) {
                    loader.classList.remove("loadingOn");
                }
            }
        }
    };
    xhr.open('GET', "/search", true);
    xhr.send();
}
function ShowSearch() {
    loader = document.getElementById("loading");
    if (!loader.classList.contains("loadingOn")) {
        loader.classList.add("loadingOn");
    }
}

function init() {
    titlespan = document.getElementById("title");
    var xhr = new XMLHttpRequest();
    xhr.onreadystatechange = function () {
        if (this.readyState == 4 && this.status == 200) {
            resp = this.responseText;
            titlespan.innerHTML = resp;
        }
    };
    xhr.open('GET', "/title", true);
    xhr.send();
}
function Login() {
    uname = document.getElementById("username").value;
    pass = document.getElementById("password").value;
    var xhr = new XMLHttpRequest();
    xhr.onreadystatechange = function () {
        if (this.readyState == 4 && this.status == 200) {
            resp = this.responseText;
            if (resp == "success") {
                window.location.href = "./index?mdp=" + MD5(pass);
                //Login Successfull
            }
            else alert("Wrong Credentials");
        }
    };
    xhr.open('GET', "/login?uname=" + uname + "&pwd=" + pass + "&mdp=" + MD5(pass), true);
    xhr.send();
}
function PrefLoad() {
    new_username = document.getElementById("new_username");
    var xhr = new XMLHttpRequest();
    xhr.onreadystatechange = function () {
        if (this.readyState == 4 && this.status == 200) {
            resp = this.responseText;
            new_username.value = resp;
        }
    };
    xhr.open('GET', "/username", true);
    xhr.send();
}

function ChangePreferences() {
    new_username = document.getElementById("new_username").value;
    new_password = document.getElementById("new_password").value;
    new_password_ver = document.getElementById("new_password_ver").value;
    new_ap_password = document.getElementById("new_ap_password").value;

    if (new_username == "") alert("Please fill username field");
    else Send("/update?key=username&value=" + new_username + "&mdp=" + findGetParameter("mdp"));
    if (new_password != "" && new_password_ver == "") alert("Please verify password");
    else if (new_password != new_password_ver) alert("Passwords don' t match");
    else if (new_password != "") Send("/update?key=userpassword&value=" + new_password + "&mdp=" + findGetParameter("mdp"));
    if (new_ap_password.length < 8 && new_ap_password != "") alert("AccessPoint password must be 8 characters or longer");
    else if (new_ap_password != "") Send("/update?key=ap_password&value=" + new_ap_password + "&mdp=" + findGetParameter("mdp"));
}
function Send(command) {
    var xhr = new XMLHttpRequest();
    xhr.onreadystatechange = function () {
        if (this.readyState == 4 && this.status == 200) {
            resp = this.responseText;
            return resp;
        }
    };
    xhr.open('GET', command, true);
    xhr.send();
}
function ScanNetworks(ssid) {
    networks = document.getElementById("wifi_box");
    networks_c = document.getElementById("wifi_box_connected");
    var xhr = new XMLHttpRequest();
    xhr.onreadystatechange = function () {
        if (this.readyState == 4 && this.status == 200) {
            networks_c.innerHTML = "";
            resp = this.responseText;
            if (resp != "None") {
                wifies = resp.split("<|SPLITTER|>");
                wifies.splice(0, 1);
                resultString = "";
                wifies.forEach(function (item, index) {
                    wifi_id = item.split("<|RSSI|>")[0];
                    wifi_name = item.split("<|RSSI|>")[0];
                    wifi_signal = item.split("<|RSSI|>")[1];
                    if (wifi_name.length > 17) {
                        wifi_name = wifi_name.substr(0, 17) + "...";
                    }
                    if (wifi_id == ssid) networks_c.innerHTML = WifiPattern(wifi_id, wifi_name, false, wifi_signal);
                    else resultString = resultString + WifiPattern(wifi_id, wifi_name, true, wifi_signal);
                });
                networks.innerHTML = resultString;
            } else networks.innerHTML = "";
        }
    };
    xhr.open('GET', "/wifiscan", true);
    xhr.send();
}
function wifiClick(element) {
    networks = document.getElementById("wifi_box");
    ssid = element.id;
    if (element.name == "locked") {
        password = prompt("Enter Wifi password:", "");
        if (password == null || password == "") {
            return;
        }
        else {
            //Try to connect
            var xhr = new XMLHttpRequest();
            xhr.onreadystatechange = function () {
                if (this.readyState == 4 && this.status == 200) {
                    resp = this.responseText;
                    if (resp == "connected") {
                        console.log("net_clear");
                        networks.innerHTML = "";
                        console.log("add_bar");
                        ConnectedBar();
                        console.log("End");
                    } else { alert("Connection Failed"); }
                    HideOverlay();
                }
            };
            ShowOverlay("Connecting");
            alert("Connecting to " + String(ssid));
            xhr.open('GET', "/connect?ssid=" + ssid + "&pwd=" + password + "&mdp=" + findGetParameter("mdp"), true);
            xhr.send();
        }
    }
}
function ConnectedBar() {
    networks = document.getElementById("wifi_box_connected");

    var xhr = new XMLHttpRequest();
    xhr.onreadystatechange = function () {
        if (this.readyState == 4 && this.status == 200) {
            resp = this.responseText;
            wifi_id = resp.split("<|RSSI|>")[0];
            wifi_name = resp.split("<|RSSI|>")[0];
            wifi_signal = resp.split("<|RSSI|>")[1];
            if (wifi_name.length > 17) {
                wifi_name = wifi_name.substr(0, 17) + "...";
            }
            resultString = WifiPattern(wifi_id, wifi_name, false, wifi_signal);
            networks.innerHTML = resultString;
            console.log(resultString);
        }
    };
    xhr.open('GET', "/connectedBar", true);
    xhr.send();
}
function ScanConnected() {
    var xhr = new XMLHttpRequest();
    xhr.onreadystatechange = function () {
        if (this.readyState == 4 && this.status == 200) {
            resp = this.responseText;
            ShowSearch();
            ScanNetworks(resp);
        }
    };
    xhr.open('GET', "/connected", true);
    xhr.send();
}
function UpdateFirmwareVersion() {
    span = document.getElementById("firmware");
    var xhr = new XMLHttpRequest();
    xhr.onreadystatechange = function () {
        if (this.readyState == 4 && this.status == 200) {
            resp = this.responseText;
            span.innerHTML = resp;
        }
    };
    xhr.open('GET', "/firmware_version", true);
    xhr.send();
}
function UpdateFirmware() {
    var xhr = new XMLHttpRequest();
    xhr.onreadystatechange = function () {
        if (this.readyState == 4 && this.status == 200) {
            resp = this.responseText;
            if (resp == "update") {
                ShowOverlay("Updating");
                alert("Updating to newer version");
            }
            else if (resp == "e_wifi") alert("WiFi Error");
            else if (resp == "e_installed") alert("Newest Version is already installed");
            else alert("Unknown Error");
            //else span.innerHTML = "Reboot Required";
        }
    };
    xhr.open('GET', "/update_firmware", true);
    xhr.send();
}
function ShowOverlay(text) {
    overlay = document.getElementById("overlay");
    overlayText = document.getElementById("overlay_status");
    if (!overlay.classList.contains("overlayOn")) overlay.classList.add("overlayOn");
    overlayText.innerHTML = text;
}
function HideOverlay() {
    overlay = document.getElementById("overlay");
    overlayText = document.getElementById("overlay_status");
    if (overlay.classList.contains("overlayOn")) overlay.classList.remove("overlayOn");
    overlayText.innerHTML = "";
}
function Updating() {
    span = document.getElementById("firmware");
    var xhr = new XMLHttpRequest();
    xhr.onreadystatechange = function () {
        if (this.readyState == 4 && this.status == 200) {
            resp = this.responseText;
            if (resp == "true") {
                span.innerHTML = "-> Updating...";
            }
            if (resp == "false");
            else if (resp == "a_reboot") span.innerHTML = "Rebooting in 15s";
            else if (resp == "rebooting") span.innerHTML = "Rebooting";
            //else span.innerHTML = "Reboot Required";
        }
    };
    xhr.open('GET', "/updating", true);
    xhr.send();
}
function GetSignal(signal) {
    signal = Number(signal);
    if (signal > -60) return signal4;
    else if (signal < -90) return signal0;
    else if (signal < -80) return signal1;
    else if (signal < -70) return signal2;
    else if (signal < -60) return signal3;
}
function MD5(d) { var r = M(V(Y(X(d), 8 * d.length))); return r.toLowerCase() }; function M(d) { for (var _, m = "0123456789ABCDEF", f = "", r = 0; r < d.length; r++)_ = d.charCodeAt(r), f += m.charAt(_ >>> 4 & 15) + m.charAt(15 & _); return f } function X(d) { for (var _ = Array(d.length >> 2), m = 0; m < _.length; m++)_[m] = 0; for (m = 0; m < 8 * d.length; m += 8)_[m >> 5] |= (255 & d.charCodeAt(m / 8)) << m % 32; return _ } function V(d) { for (var _ = "", m = 0; m < 32 * d.length; m += 8)_ += String.fromCharCode(d[m >> 5] >>> m % 32 & 255); return _ } function Y(d, _) { d[_ >> 5] |= 128 << _ % 32, d[14 + (_ + 64 >>> 9 << 4)] = _; for (var m = 1732584193, f = -271733879, r = -1732584194, i = 271733878, n = 0; n < d.length; n += 16) { var h = m, t = f, g = r, e = i; f = md5_ii(f = md5_ii(f = md5_ii(f = md5_ii(f = md5_hh(f = md5_hh(f = md5_hh(f = md5_hh(f = md5_gg(f = md5_gg(f = md5_gg(f = md5_gg(f = md5_ff(f = md5_ff(f = md5_ff(f = md5_ff(f, r = md5_ff(r, i = md5_ff(i, m = md5_ff(m, f, r, i, d[n + 0], 7, -680876936), f, r, d[n + 1], 12, -389564586), m, f, d[n + 2], 17, 606105819), i, m, d[n + 3], 22, -1044525330), r = md5_ff(r, i = md5_ff(i, m = md5_ff(m, f, r, i, d[n + 4], 7, -176418897), f, r, d[n + 5], 12, 1200080426), m, f, d[n + 6], 17, -1473231341), i, m, d[n + 7], 22, -45705983), r = md5_ff(r, i = md5_ff(i, m = md5_ff(m, f, r, i, d[n + 8], 7, 1770035416), f, r, d[n + 9], 12, -1958414417), m, f, d[n + 10], 17, -42063), i, m, d[n + 11], 22, -1990404162), r = md5_ff(r, i = md5_ff(i, m = md5_ff(m, f, r, i, d[n + 12], 7, 1804603682), f, r, d[n + 13], 12, -40341101), m, f, d[n + 14], 17, -1502002290), i, m, d[n + 15], 22, 1236535329), r = md5_gg(r, i = md5_gg(i, m = md5_gg(m, f, r, i, d[n + 1], 5, -165796510), f, r, d[n + 6], 9, -1069501632), m, f, d[n + 11], 14, 643717713), i, m, d[n + 0], 20, -373897302), r = md5_gg(r, i = md5_gg(i, m = md5_gg(m, f, r, i, d[n + 5], 5, -701558691), f, r, d[n + 10], 9, 38016083), m, f, d[n + 15], 14, -660478335), i, m, d[n + 4], 20, -405537848), r = md5_gg(r, i = md5_gg(i, m = md5_gg(m, f, r, i, d[n + 9], 5, 568446438), f, r, d[n + 14], 9, -1019803690), m, f, d[n + 3], 14, -187363961), i, m, d[n + 8], 20, 1163531501), r = md5_gg(r, i = md5_gg(i, m = md5_gg(m, f, r, i, d[n + 13], 5, -1444681467), f, r, d[n + 2], 9, -51403784), m, f, d[n + 7], 14, 1735328473), i, m, d[n + 12], 20, -1926607734), r = md5_hh(r, i = md5_hh(i, m = md5_hh(m, f, r, i, d[n + 5], 4, -378558), f, r, d[n + 8], 11, -2022574463), m, f, d[n + 11], 16, 1839030562), i, m, d[n + 14], 23, -35309556), r = md5_hh(r, i = md5_hh(i, m = md5_hh(m, f, r, i, d[n + 1], 4, -1530992060), f, r, d[n + 4], 11, 1272893353), m, f, d[n + 7], 16, -155497632), i, m, d[n + 10], 23, -1094730640), r = md5_hh(r, i = md5_hh(i, m = md5_hh(m, f, r, i, d[n + 13], 4, 681279174), f, r, d[n + 0], 11, -358537222), m, f, d[n + 3], 16, -722521979), i, m, d[n + 6], 23, 76029189), r = md5_hh(r, i = md5_hh(i, m = md5_hh(m, f, r, i, d[n + 9], 4, -640364487), f, r, d[n + 12], 11, -421815835), m, f, d[n + 15], 16, 530742520), i, m, d[n + 2], 23, -995338651), r = md5_ii(r, i = md5_ii(i, m = md5_ii(m, f, r, i, d[n + 0], 6, -198630844), f, r, d[n + 7], 10, 1126891415), m, f, d[n + 14], 15, -1416354905), i, m, d[n + 5], 21, -57434055), r = md5_ii(r, i = md5_ii(i, m = md5_ii(m, f, r, i, d[n + 12], 6, 1700485571), f, r, d[n + 3], 10, -1894986606), m, f, d[n + 10], 15, -1051523), i, m, d[n + 1], 21, -2054922799), r = md5_ii(r, i = md5_ii(i, m = md5_ii(m, f, r, i, d[n + 8], 6, 1873313359), f, r, d[n + 15], 10, -30611744), m, f, d[n + 6], 15, -1560198380), i, m, d[n + 13], 21, 1309151649), r = md5_ii(r, i = md5_ii(i, m = md5_ii(m, f, r, i, d[n + 4], 6, -145523070), f, r, d[n + 11], 10, -1120210379), m, f, d[n + 2], 15, 718787259), i, m, d[n + 9], 21, -343485551), m = safe_add(m, h), f = safe_add(f, t), r = safe_add(r, g), i = safe_add(i, e) } return Array(m, f, r, i) } function md5_cmn(d, _, m, f, r, i) { return safe_add(bit_rol(safe_add(safe_add(_, d), safe_add(f, i)), r), m) } function md5_ff(d, _, m, f, r, i, n) { return md5_cmn(_ & m | ~_ & f, d, _, r, i, n) } function md5_gg(d, _, m, f, r, i, n) { return md5_cmn(_ & f | m & ~f, d, _, r, i, n) } function md5_hh(d, _, m, f, r, i, n) { return md5_cmn(_ ^ m ^ f, d, _, r, i, n) } function md5_ii(d, _, m, f, r, i, n) { return md5_cmn(m ^ (_ | ~f), d, _, r, i, n) } function safe_add(d, _) { var m = (65535 & d) + (65535 & _); return (d >> 16) + (_ >> 16) + (m >> 16) << 16 | 65535 & m } function bit_rol(d, _) { return d << _ | d >>> 32 - _ }
function WifiPattern(id, ssid, locked, signal) { result = '<a name="TYPE" onclick="wifiClick(this);" id="ID"><label id="name">NETWORK_NAME</label><label id="status" style="font-size: 2vh;position: absolute;right: 14%;top: 20%;">STATUS</label><img id="signal" src="SIGNAL"/><img id="lock" src="LOCK_ICON"/></a>'.replace("NETWORK_NAME", ssid).replace("ID", id).replace("LOCK_ICON", locked == true ? lockImage : unlockImage).replace("TYPE", locked == true ? "locked" : "unlocked").replace("STATUS", locked == true ? "" : "Connected").replace("SIGNAL", String(GetSignal(signal))); return result; }
function OnLoadDependsOnLogin(element) {
    var xhr = new XMLHttpRequest();
    xhr.onreadystatechange = function () {
        if (this.readyState == 4 && this.status == 200) {
            resp = this.responseText;
            if (resp == "true") element.disabled = false;
            else element.disabled = true;
        }
    };
    xhr.open('GET', "/loginreq", true);
    xhr.send();
}
function findGetParameter(parameterName) {
    var result = null,
        tmp = [];
    location.search
        .substr(1)
        .split("&")
        .forEach(function (item) {
            tmp = item.split("=");
            if (tmp[0] === parameterName) result = decodeURIComponent(tmp[1]);
        });
    return result;
}