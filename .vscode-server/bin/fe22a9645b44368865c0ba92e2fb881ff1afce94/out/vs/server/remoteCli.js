/*!--------------------------------------------------------
 * Copyright (C) Microsoft Corporation. All rights reserved.
 *--------------------------------------------------------*/
(function(){var e=["require","exports","vs/base/common/path","os","fs","vs/base/common/platform","vs/base/common/process","vs/base/node/terminalEncoding","child_process","vs/nls!vs/platform/environment/node/argv","vs/platform/environment/node/stdin","vs/platform/environment/node/waitMarkerFile","vs/platform/environment/node/argv","vs/nls","vs/nls!vs/server/remoteCli","vscode-minimist","vs/server/remoteCli","url","http"],t=function(t){for(var n=[],o=0,r=t.length;o<r;o++)n[o]=e[t[o]];return n};define(e[5],t([0,1]),(function(e,t){"use strict";Object.defineProperty(t,"__esModule",{value:!0});let n=!1,o=!1,r=!1,i=!1,s=!1,l=!1,a=void 0,c="en",d=void 0,p=void 0;const f="undefined"!=typeof process&&void 0!==process.versions&&void 0!==process.versions.electron&&"renderer"===process.type;if("object"!=typeof navigator||f){if("object"==typeof process){n="win32"===process.platform,o="darwin"===process.platform,r="linux"===process.platform,a="en",c="en";const e=process.env.VSCODE_NLS_CONFIG;if(e)try{
const t=JSON.parse(e),n=t.availableLanguages["*"];a=t.locale,c=n||"en",d=t._translationsConfigFile}catch(e){}i=!0}}else p=navigator.userAgent,n=p.indexOf("Windows")>=0,o=p.indexOf("Macintosh")>=0,l=p.indexOf("Macintosh")>=0&&!!navigator.maxTouchPoints&&navigator.maxTouchPoints>0,r=p.indexOf("Linux")>=0,s=!0,c=a=navigator.language;!function(e){e[e.Web=0]="Web",e[e.Mac=1]="Mac",e[e.Linux=2]="Linux",e[e.Windows=3]="Windows"}(t.Platform||(t.Platform={})),t.PlatformToString=function(e){switch(e){case 0:return"Web";case 1:return"Mac";case 2:return"Linux";case 3:return"Windows"}};let u=0;o?u=1:n?u=3:r&&(u=2),t.isWindows=n,t.isMacintosh=o,t.isLinux=r,t.isNative=i,t.isWeb=s,t.isIOS=l,t.platform=u,t.userAgent=p,t.isRootUser=function(){return i&&!n&&0===process.getuid()},t.language=c,function(e){e.value=function(){return t.language},e.isDefaultVariant=function(){return 2===t.language.length?"en"===t.language:t.language.length>=3&&("e"===t.language[0]&&"n"===t.language[1]&&"-"===t.language[2])},e.isDefault=function(){
return"en"===t.language}}(t.Language||(t.Language={})),t.locale=a,t.translationsConfigFile=d;const g="object"==typeof self?self:"object"==typeof global?global:{};t.globals=g,t.setImmediate=function(){if(t.globals.setImmediate)return t.globals.setImmediate.bind(t.globals);if("function"==typeof t.globals.postMessage&&!t.globals.importScripts){let e=[];t.globals.addEventListener("message",t=>{if(t.data&&t.data.vscodeSetImmediateId)for(let n=0,o=e.length;n<o;n++){const o=e[n];if(o.id===t.data.vscodeSetImmediateId)return e.splice(n,1),void o.callback()}});let n=0;return o=>{const r=++n;e.push({id:r,callback:o}),t.globals.postMessage({vscodeSetImmediateId:r},"*")}}if("undefined"!=typeof process&&"function"==typeof process.nextTick)return process.nextTick.bind(process);const e=Promise.resolve();return t=>e.then(t)}(),function(e){e[e.Windows=1]="Windows",e[e.Macintosh=2]="Macintosh",e[e.Linux=3]="Linux"}(t.OperatingSystem||(t.OperatingSystem={})),t.OS=o?2:n?1:3})),define(e[6],t([0,1,5]),(function(e,t,n){"use strict"
;Object.defineProperty(t,"__esModule",{value:!0});const o="undefined"==typeof process?{cwd:()=>"/",env:Object.create(null),get platform(){return n.isWindows?"win32":n.isMacintosh?"darwin":"linux"},nextTick:e=>n.setImmediate(e)}:process;t.cwd=o.cwd,t.env=o.env,t.platform=o.platform,t.nextTick=o.nextTick})),define(e[2],t([0,1,6]),(function(e,t,n){"use strict";Object.defineProperty(t,"__esModule",{value:!0});const o=65,r=97,i=90,s=122,l=46,a=47,c=92;class d extends Error{constructor(e,t,n){let o;"string"==typeof t&&0===t.indexOf("not ")?(o="must not be",t=t.replace(/^not /,"")):o="must be";const r=-1!==e.indexOf(".")?"property":"argument";let i=`The "${e}" ${r} ${o} of type ${t}`;super(i+=`. Received type ${typeof n}`),this.code="ERR_INVALID_ARG_TYPE"}}function p(e,t){if("string"!=typeof e)throw new d(t,"string",e)}function f(e){return e===a||e===c}function u(e){return e===a}function g(e){return e>=o&&e<=i||e>=r&&e<=s}function h(e,t,n,o){let r,i="",s=0,c=-1,d=0;for(let p=0;p<=e.length;++p){
if(p<e.length)r=e.charCodeAt(p);else{if(o(r))break;r=a}if(o(r)){if(c===p-1||1===d);else if(c!==p-1&&2===d){if(i.length<2||2!==s||i.charCodeAt(i.length-1)!==l||i.charCodeAt(i.length-2)!==l){if(i.length>2){const e=i.lastIndexOf(n);-1===e?(i="",s=0):s=(i=i.slice(0,e)).length-1-i.lastIndexOf(n),c=p,d=0;continue}if(2===i.length||1===i.length){i="",s=0,c=p,d=0;continue}}t&&(i.length>0?i+=`${n}..`:i="..",s=2)}else i.length>0?i+=n+e.slice(c+1,p):i=e.slice(c+1,p),s=p-c-1;c=p,d=0}else r===l&&-1!==d?++d:d=-1}return i}function m(e,t){const n=t.dir||t.root,o=t.base||(t.name||"")+(t.ext||"");return n?n===t.root?n+o:n+e+o:o}t.win32={resolve(...e){let t="",o="",r=!1;for(let i=e.length-1;i>=-1;i--){let s;if(i>=0?s=e[i]:t?void 0!==(s=n.env["="+t]||n.cwd())&&s.slice(0,3).toLowerCase()===t.toLowerCase()+"\\"||(s=t+"\\"):s=n.cwd(),p(s,"path"),0===s.length)continue;const l=s.length;let a=0,c="",d=!1;const u=s.charCodeAt(0);if(l>1)if(f(u))if(d=!0,f(s.charCodeAt(1))){let e=2,t=e;for(;e<l&&!f(s.charCodeAt(e));++e);if(e<l&&e!==t){
const n=s.slice(t,e);for(t=e;e<l&&f(s.charCodeAt(e));++e);if(e<l&&e!==t){for(t=e;e<l&&!f(s.charCodeAt(e));++e);e===l?(c="\\\\"+n+"\\"+s.slice(t),a=e):e!==t&&(c="\\\\"+n+"\\"+s.slice(t,e),a=e)}}}else a=1;else g(u)&&58===s.charCodeAt(1)&&(c=s.slice(0,2),a=2,l>2&&f(s.charCodeAt(2))&&(d=!0,a=3));else f(u)&&(a=1,d=!0);if(!(c.length>0&&t.length>0&&c.toLowerCase()!==t.toLowerCase())&&(0===t.length&&c.length>0&&(t=c),r||(o=s.slice(a)+"\\"+o,r=d),t.length>0&&r))break}return t+(r?"\\":"")+(o=h(o,!r,"\\",f))||"."},normalize(e){p(e,"path");const t=e.length;if(0===t)return".";let n,o=0,r=!1;const i=e.charCodeAt(0);if(t>1)if(f(i))if(r=!0,f(e.charCodeAt(1))){let r=2,i=r;for(;r<t&&!f(e.charCodeAt(r));++r);if(r<t&&r!==i){const s=e.slice(i,r);for(i=r;r<t&&f(e.charCodeAt(r));++r);if(r<t&&r!==i){for(i=r;r<t&&!f(e.charCodeAt(r));++r);if(r===t)return"\\\\"+s+"\\"+e.slice(i)+"\\";r!==i&&(n="\\\\"+s+"\\"+e.slice(i,r),o=r)}}}else o=1;else g(i)&&58===e.charCodeAt(1)&&(n=e.slice(0,2),o=2,t>2&&f(e.charCodeAt(2))&&(r=!0,
o=3));else if(f(i))return"\\";let s;return 0!==(s=o<t?h(e.slice(o),!r,"\\",f):"").length||r||(s="."),s.length>0&&f(e.charCodeAt(t-1))&&(s+="\\"),void 0===n?r?s.length>0?"\\"+s:"\\":s.length>0?s:"":r?s.length>0?n+"\\"+s:n+"\\":s.length>0?n+s:n},isAbsolute(e){p(e,"path");const t=e.length;if(0===t)return!1;const n=e.charCodeAt(0);return!!f(n)||!!(g(n)&&t>2&&58===e.charCodeAt(1)&&f(e.charCodeAt(2)))},join(...e){if(0===e.length)return".";let n,o;for(let t=0;t<e.length;++t){const r=e[t];p(r,"path"),r.length>0&&(void 0===n?n=o=r:n+="\\"+r)}if(void 0===n)return".";let r=!0,i=0;if("string"==typeof o&&f(o.charCodeAt(0))){++i;const e=o.length;e>1&&f(o.charCodeAt(1))&&(++i,e>2&&(f(o.charCodeAt(2))?++i:r=!1))}if(r){for(;i<n.length&&f(n.charCodeAt(i));++i);i>=2&&(n="\\"+n.slice(i))}return t.win32.normalize(n)},relative(e,n){if(p(e,"from"),p(n,"to"),e===n)return"";const o=t.win32.resolve(e),r=t.win32.resolve(n);if(o===r)return"";if((e=o.toLowerCase())===(n=r.toLowerCase()))return"";let i=0
;for(;i<e.length&&e.charCodeAt(i)===c;++i);let s=e.length;for(;s-1>i&&e.charCodeAt(s-1)===c;--s);const l=s-i;let a=0;for(;a<n.length&&n.charCodeAt(a)===c;++a);let d=n.length;for(;d-1>a&&n.charCodeAt(d-1)===c;--d);const f=d-a,u=l<f?l:f;let g=-1,h=0;for(;h<=u;++h){if(h===u){if(f>u){if(n.charCodeAt(a+h)===c)return r.slice(a+h+1);if(2===h)return r.slice(a+h)}l>u&&(e.charCodeAt(i+h)===c?g=h:2===h&&(g=3));break}const t=e.charCodeAt(i+h);if(t!==n.charCodeAt(a+h))break;t===c&&(g=h)}if(h!==u&&-1===g)return r;let m="";for(-1===g&&(g=0),h=i+g+1;h<=s;++h)h!==s&&e.charCodeAt(h)!==c||(0===m.length?m+="..":m+="\\..");return m.length>0?m+r.slice(a+g,d):(a+=g,r.charCodeAt(a)===c&&++a,r.slice(a,d))},toNamespacedPath(e){if("string"!=typeof e)return e;if(0===e.length)return"";const n=t.win32.resolve(e);if(n.length>=3)if(n.charCodeAt(0)===c){if(n.charCodeAt(1)===c){const e=n.charCodeAt(2);if(63!==e&&e!==l)return"\\\\?\\UNC\\"+n.slice(2)}}else if(g(n.charCodeAt(0))&&58===n.charCodeAt(1)&&n.charCodeAt(2)===c)return"\\\\?\\"+n
;return e},dirname(e){p(e,"path");const t=e.length;if(0===t)return".";let n=-1,o=-1,r=!0,i=0;const s=e.charCodeAt(0);if(t>1)if(f(s)){if(n=i=1,f(e.charCodeAt(1))){let o=2,r=o;for(;o<t&&!f(e.charCodeAt(o));++o);if(o<t&&o!==r){for(r=o;o<t&&f(e.charCodeAt(o));++o);if(o<t&&o!==r){for(r=o;o<t&&!f(e.charCodeAt(o));++o);if(o===t)return e;o!==r&&(n=i=o+1)}}}}else g(s)&&58===e.charCodeAt(1)&&(n=i=2,t>2&&f(e.charCodeAt(2))&&(n=i=3));else if(f(s))return e;for(let n=t-1;n>=i;--n)if(f(e.charCodeAt(n))){if(!r){o=n;break}}else r=!1;if(-1===o){if(-1===n)return".";o=n}return e.slice(0,o)},basename(e,t){void 0!==t&&p(t,"ext"),p(e,"path");let n,o=0,r=-1,i=!0;if(e.length>=2){g(e.charCodeAt(0))&&58===e.charCodeAt(1)&&(o=2)}if(void 0!==t&&t.length>0&&t.length<=e.length){if(t.length===e.length&&t===e)return"";let s=t.length-1,l=-1;for(n=e.length-1;n>=o;--n){const a=e.charCodeAt(n);if(f(a)){if(!i){o=n+1;break}}else-1===l&&(i=!1,l=n+1),s>=0&&(a===t.charCodeAt(s)?-1==--s&&(r=n):(s=-1,r=l))}return o===r?r=l:-1===r&&(r=e.length),
e.slice(o,r)}for(n=e.length-1;n>=o;--n)if(f(e.charCodeAt(n))){if(!i){o=n+1;break}}else-1===r&&(i=!1,r=n+1);return-1===r?"":e.slice(o,r)},extname(e){p(e,"path");let t=0,n=-1,o=0,r=-1,i=!0,s=0;e.length>=2&&58===e.charCodeAt(1)&&g(e.charCodeAt(0))&&(t=o=2);for(let a=e.length-1;a>=t;--a){const t=e.charCodeAt(a);if(f(t)){if(!i){o=a+1;break}}else-1===r&&(i=!1,r=a+1),t===l?-1===n?n=a:1!==s&&(s=1):-1!==n&&(s=-1)}return-1===n||-1===r||0===s||1===s&&n===r-1&&n===o+1?"":e.slice(n,r)},format(e){if(null===e||"object"!=typeof e)throw new d("pathObject","Object",e);return m("\\",e)},parse(e){p(e,"path");const t={root:"",dir:"",base:"",ext:"",name:""};if(0===e.length)return t;const n=e.length;let o=0,r=e.charCodeAt(0);if(n>1){if(f(r)){if(o=1,f(e.charCodeAt(1))){let t=2,r=t;for(;t<n&&!f(e.charCodeAt(t));++t);if(t<n&&t!==r){for(r=t;t<n&&f(e.charCodeAt(t));++t);if(t<n&&t!==r){for(r=t;t<n&&!f(e.charCodeAt(t));++t);t===n?o=t:t!==r&&(o=t+1)}}}}else if(g(r)&&58===e.charCodeAt(1)){if(o=2,!(n>2))return t.root=t.dir=e,t
;if(f(e.charCodeAt(2))){if(3===n)return t.root=t.dir=e,t;o=3}}}else if(f(r))return t.root=t.dir=e,t;o>0&&(t.root=e.slice(0,o));let i=-1,s=o,a=-1,c=!0,d=e.length-1,u=0;for(;d>=o;--d)if(f(r=e.charCodeAt(d))){if(!c){s=d+1;break}}else-1===a&&(c=!1,a=d+1),r===l?-1===i?i=d:1!==u&&(u=1):-1!==i&&(u=-1);return-1===i||-1===a||0===u||1===u&&i===a-1&&i===s+1?-1!==a&&(t.base=t.name=e.slice(s,a)):(t.name=e.slice(s,i),t.base=e.slice(s,a),t.ext=e.slice(i,a)),t.dir=s>0&&s!==o?e.slice(0,s-1):t.root,t},sep:"\\",delimiter:";",win32:null,posix:null},t.posix={resolve(...e){let t="",o=!1;for(let r=e.length-1;r>=-1&&!o;r--){let i;p(i=r>=0?e[r]:n.cwd(),"path"),0!==i.length&&(t=i+"/"+t,o=i.charCodeAt(0)===a)}return t=h(t,!o,"/",u),o?t.length>0?"/"+t:"/":t.length>0?t:"."},normalize(e){if(p(e,"path"),0===e.length)return".";const t=e.charCodeAt(0)===a,n=e.charCodeAt(e.length-1)===a;return 0!==(e=h(e,!t,"/",u)).length||t||(e="."),e.length>0&&n&&(e+="/"),t?"/"+e:e},isAbsolute:e=>(p(e,"path"),e.length>0&&e.charCodeAt(0)===a),join(...e){
if(0===e.length)return".";let n;for(let t=0;t<e.length;++t){const e=arguments[t];p(e,"path"),e.length>0&&(void 0===n?n=e:n+="/"+e)}return void 0===n?".":t.posix.normalize(n)},relative(e,n){if(p(e,"from"),p(n,"to"),e===n)return"";if((e=t.posix.resolve(e))===(n=t.posix.resolve(n)))return"";let o=1;for(;o<e.length&&e.charCodeAt(o)===a;++o);const r=e.length,i=r-o;let s=1;for(;s<n.length&&n.charCodeAt(s)===a;++s);const l=n.length-s,c=i<l?i:l;let d=-1,f=0;for(;f<=c;++f){if(f===c){if(l>c){if(n.charCodeAt(s+f)===a)return n.slice(s+f+1);if(0===f)return n.slice(s+f)}else i>c&&(e.charCodeAt(o+f)===a?d=f:0===f&&(d=0));break}const t=e.charCodeAt(o+f);if(t!==n.charCodeAt(s+f))break;t===a&&(d=f)}let u="";for(f=o+d+1;f<=r;++f)f!==r&&e.charCodeAt(f)!==a||(0===u.length?u+="..":u+="/..");return u.length>0?u+n.slice(s+d):(s+=d,n.charCodeAt(s)===a&&++s,n.slice(s))},toNamespacedPath:e=>e,dirname(e){if(p(e,"path"),0===e.length)return".";const t=e.charCodeAt(0)===a;let n=-1,o=!0;for(let t=e.length-1;t>=1;--t)if(e.charCodeAt(t)===a){
if(!o){n=t;break}}else o=!1;return-1===n?t?"/":".":t&&1===n?"//":e.slice(0,n)},basename(e,t){void 0!==t&&p(t,"ext"),p(e,"path");let n,o=0,r=-1,i=!0;if(void 0!==t&&t.length>0&&t.length<=e.length){if(t.length===e.length&&t===e)return"";let s=t.length-1,l=-1;for(n=e.length-1;n>=0;--n){const c=e.charCodeAt(n);if(c===a){if(!i){o=n+1;break}}else-1===l&&(i=!1,l=n+1),s>=0&&(c===t.charCodeAt(s)?-1==--s&&(r=n):(s=-1,r=l))}return o===r?r=l:-1===r&&(r=e.length),e.slice(o,r)}for(n=e.length-1;n>=0;--n)if(e.charCodeAt(n)===a){if(!i){o=n+1;break}}else-1===r&&(i=!1,r=n+1);return-1===r?"":e.slice(o,r)},extname(e){p(e,"path");let t=-1,n=0,o=-1,r=!0,i=0;for(let s=e.length-1;s>=0;--s){const c=e.charCodeAt(s);if(c!==a)-1===o&&(r=!1,o=s+1),c===l?-1===t?t=s:1!==i&&(i=1):-1!==t&&(i=-1);else if(!r){n=s+1;break}}return-1===t||-1===o||0===i||1===i&&t===o-1&&t===n+1?"":e.slice(t,o)},format(e){if(null===e||"object"!=typeof e)throw new d("pathObject","Object",e);return m("/",e)},parse(e){p(e,"path");const t={root:"",dir:"",base:"",ext:"",
name:""};if(0===e.length)return t;const n=e.charCodeAt(0)===a;let o;n?(t.root="/",o=1):o=0;let r=-1,i=0,s=-1,c=!0,d=e.length-1,f=0;for(;d>=o;--d){const t=e.charCodeAt(d);if(t!==a)-1===s&&(c=!1,s=d+1),t===l?-1===r?r=d:1!==f&&(f=1):-1!==r&&(f=-1);else if(!c){i=d+1;break}}return-1===r||-1===s||0===f||1===f&&r===s-1&&r===i+1?-1!==s&&(t.base=t.name=0===i&&n?e.slice(1,s):e.slice(i,s)):(0===i&&n?(t.name=e.slice(1,r),t.base=e.slice(1,s)):(t.name=e.slice(i,r),t.base=e.slice(i,s)),t.ext=e.slice(r,s)),i>0?t.dir=e.slice(0,i-1):n&&(t.dir="/"),t},sep:"/",delimiter:":",win32:null,posix:null},t.posix.win32=t.win32.win32=t.win32,t.posix.posix=t.win32.posix=t.posix,t.normalize="win32"===n.platform?t.win32.normalize:t.posix.normalize,t.isAbsolute="win32"===n.platform?t.win32.isAbsolute:t.posix.isAbsolute,t.join="win32"===n.platform?t.win32.join:t.posix.join,t.resolve="win32"===n.platform?t.win32.resolve:t.posix.resolve,t.relative="win32"===n.platform?t.win32.relative:t.posix.relative,
t.dirname="win32"===n.platform?t.win32.dirname:t.posix.dirname,t.basename="win32"===n.platform?t.win32.basename:t.posix.basename,t.extname="win32"===n.platform?t.win32.extname:t.posix.extname,t.format="win32"===n.platform?t.win32.format:t.posix.format,t.parse="win32"===n.platform?t.win32.parse:t.posix.parse,t.toNamespacedPath="win32"===n.platform?t.win32.toNamespacedPath:t.posix.toNamespacedPath,t.sep="win32"===n.platform?t.win32.sep:t.posix.sep,t.delimiter="win32"===n.platform?t.win32.delimiter:t.posix.delimiter})),define(e[7],t([0,1,8,3]),(function(e,t,n,o){"use strict";Object.defineProperty(t,"__esModule",{value:!0});const r={437:"cp437",850:"cp850",852:"cp852",855:"cp855",857:"cp857",860:"cp860",861:"cp861",863:"cp863",865:"cp865",866:"cp866",869:"cp869",936:"cp936",1252:"cp1252"};const i={ibm866:"cp866",big5:"cp950"},s="utf8";t.resolveTerminalEncoding=async function(e){let t;const l=process.env.VSCODE_CLI_ENCODING;l?(e&&console.log(`Found VSCODE_CLI_ENCODING variable: ${l}`),
t=Promise.resolve(l)):t="win32"===o.platform()?new Promise(t=>{e&&console.log('Running "chcp" to detect terminal encoding...'),n.exec("chcp",(e,n,o)=>{if(n){const e=Object.keys(r);for(const o of e)if(n.indexOf(o)>=0)return t(r[o])}return t(void 0)})}):new Promise(t=>{e&&console.log('Running "locale charmap" to detect terminal encoding...'),n.exec("locale charmap",(e,n,o)=>t(n))});const a=await t;return e&&console.log(`Detected raw terminal encoding: ${a}`),a&&"utf-8"!==a.toLowerCase()&&a.toLowerCase()!==s?function(e){const t=e.replace(/[^a-zA-Z0-9]/g,"").toLowerCase();return i[t]||t}(a):s}})),define(e[9],t([13,14]),(function(e,t){return e.create("vs/platform/environment/node/argv",t)})),define(e[10],t([0,1,2,4,3,7]),(function(e,t,n,o,r,i){"use strict";Object.defineProperty(t,"__esModule",{value:!0}),t.hasStdinWithoutTty=function(){try{return!process.stdin.isTTY}catch(e){}return!1},t.stdinDataListener=function(e){return new Promise(t=>{const n=()=>t(!0);setTimeout(()=>{process.stdin.removeListener("data",n),
t(!1)},e),process.stdin.once("data",n)})},t.getStdinFilePath=function(){return n.join(r.tmpdir(),`code-stdin-${Math.random().toString(36).replace(/[^a-z]+/g,"").substr(0,3)}.txt`)},t.readFromStdin=function(t,n){const r=o.createWriteStream(t);return i.resolveTerminalEncoding(n).then(async t=>{const n=await new Promise((t,n)=>{e(["iconv-lite"],t,n)});n.encodingExists(t)||(console.log(`Unsupported terminal encoding: ${t}, falling back to UTF-8.`),t="utf8");const o=n.decodeStream(t);process.stdin.pipe(o).pipe(r)})}})),define(e[11],t([0,1,2,3,4]),(function(e,t,n,o,r){"use strict";Object.defineProperty(t,"__esModule",{value:!0}),t.createWaitMarkerFile=function(e){const t=n.join(o.tmpdir(),Math.random().toString(36).replace(/[^a-z]+/g,"").substr(0,10));try{return r.writeFileSync(t,""),e&&console.log(`Marker file for --wait created: ${t}`),t}catch(t){return void(e&&console.error(`Failed to create marker file for --wait: ${t}`))}}})),define(e[12],t([0,1,15,3,9]),(function(e,t,n,o,r){"use strict"
;Object.defineProperty(t,"__esModule",{value:!0});const i={o:r.localize(0,null),e:r.localize(1,null),t:r.localize(2,null)};t.OPTIONS={diff:{type:"boolean",cat:"o",alias:"d",args:["file","file"],description:r.localize(3,null)},add:{type:"boolean",cat:"o",alias:"a",args:"folder",description:r.localize(4,null)},goto:{type:"boolean",cat:"o",alias:"g",args:"file:line[:character]",description:r.localize(5,null)},"new-window":{type:"boolean",cat:"o",alias:"n",description:r.localize(6,null)},"reuse-window":{type:"boolean",cat:"o",alias:"r",description:r.localize(7,null)},wait:{type:"boolean",cat:"o",alias:"w",description:r.localize(8,null)},waitMarkerFilePath:{type:"string"},locale:{type:"string",cat:"o",args:"locale",description:r.localize(9,null)},"user-data-dir":{type:"string",cat:"o",args:"dir",description:r.localize(10,null)},version:{type:"boolean",cat:"o",alias:"v",description:r.localize(11,null)},help:{type:"boolean",cat:"o",alias:"h",description:r.localize(12,null)},telemetry:{type:"boolean",cat:"o",
description:r.localize(13,null)},"folder-uri":{type:"string[]",cat:"o",args:"uri",description:r.localize(14,null)},"file-uri":{type:"string[]",cat:"o",args:"uri",description:r.localize(15,null)},"extensions-dir":{type:"string",deprecates:"extensionHomePath",cat:"e",args:"dir",description:r.localize(16,null)},"builtin-extensions-dir":{type:"string"},"list-extensions":{type:"boolean",cat:"e",description:r.localize(17,null)},"show-versions":{type:"boolean",cat:"e",description:r.localize(18,null)},category:{type:"string",cat:"e",description:r.localize(19,null)},"install-extension":{type:"string[]",cat:"e",args:"extension-id | path-to-vsix",description:r.localize(20,null)},"uninstall-extension":{type:"string[]",cat:"e",args:"extension-id",description:r.localize(21,null)},"enable-proposed-api":{type:"string[]",cat:"e",args:"extension-id",description:r.localize(22,null)},verbose:{type:"boolean",cat:"t",description:r.localize(23,null)},log:{type:"string",cat:"t",args:"level",description:r.localize(24,null)},status:{
type:"boolean",alias:"s",cat:"t",description:r.localize(25,null)},"prof-startup":{type:"boolean",cat:"t",description:r.localize(26,null)},"prof-append-timers":{type:"string"},"prof-startup-prefix":{type:"string"},"disable-extensions":{type:"boolean",deprecates:"disableExtensions",cat:"t",description:r.localize(27,null)},"disable-extension":{type:"string[]",cat:"t",args:"extension-id",description:r.localize(28,null)},"inspect-extensions":{type:"string",deprecates:"debugPluginHost",args:"port",cat:"t",description:r.localize(29,null)},"inspect-brk-extensions":{type:"string",deprecates:"debugBrkPluginHost",args:"port",cat:"t",description:r.localize(30,null)},"disable-gpu":{type:"boolean",cat:"t",description:r.localize(31,null)},"max-memory":{type:"string",cat:"t",description:r.localize(32,null)},remote:{type:"string"},"locate-extension":{type:"string[]"},extensionDevelopmentPath:{type:"string[]"},extensionTestsPath:{type:"string"},"extension-development-confirm-save":{type:"boolean"},debugId:{type:"string"},
"inspect-search":{type:"string",deprecates:"debugSearch"},"inspect-brk-search":{type:"string",deprecates:"debugBrkSearch"},"export-default-configuration":{type:"string"},"install-source":{type:"string"},driver:{type:"string"},logExtensionHostCommunication:{type:"boolean"},"skip-getting-started":{type:"boolean"},"skip-release-notes":{type:"boolean"},"sticky-quickopen":{type:"boolean"},"disable-restore-windows":{type:"boolean"},"disable-telemetry":{type:"boolean"},"disable-updates":{type:"boolean"},"disable-crash-reporter":{type:"boolean"},"disable-user-env-probe":{type:"boolean"},"skip-add-to-recently-opened":{type:"boolean"},"unity-launch":{type:"boolean"},"open-url":{type:"boolean"},"file-write":{type:"boolean"},"file-chmod":{type:"boolean"},"driver-verbose":{type:"boolean"},force:{type:"boolean"},trace:{type:"boolean"},"trace-category-filter":{type:"string"},"trace-options":{type:"string"},"force-user-env":{type:"boolean"},"no-proxy-server":{type:"boolean"},"proxy-server":{type:"string"},
"proxy-bypass-list":{type:"string"},"proxy-pac-url":{type:"string"},"js-flags":{type:"string"},inspect:{type:"string"},"inspect-brk":{type:"string"},nolazy:{type:"boolean"},"force-device-scale-factor":{type:"string"},"force-renderer-accessibility":{type:"boolean"},"ignore-certificate-error":{type:"boolean"},"allow-insecure-localhost":{type:"boolean"},_urls:{type:"string[]"},_:{type:"string[]"}};const s={onUnknownOption:()=>{},onMultipleValues:()=>{}};function l(e,t){let n="";return t.args&&(n=Array.isArray(t.args)?` <${t.args.join("> <")}>`:` <${t.args}>`),t.alias?`-${t.alias} --${e}${n}`:`--${e}${n}`}function a(e,t){let n=0,o=[];for(const t in e){const r=e[t],i=l(t,r);n=Math.max(n,i.length),o.push([i,r.description])}let r=n+2+1;if(t-r<25)return o.reduce((e,t)=>e.concat([`  ${t[0]}`,`      ${t[1]}`]),[]);let i=t-r-1,s=[];for(const e of o){let t=e[0],n=d(e[1],i),o=c(r-t.length-2);s.push("  "+t+o+n[0]);for(let e=1;e<n.length;e++)s.push(c(r)+n[e])}return s}function c(e){return" ".repeat(e)}function d(e,t){
let n=[];for(;e.length;){let o=e.length<t?e.length:e.lastIndexOf(" ",t),r=e.slice(0,o).trim();e=e.slice(o),n.push(r)}return n}t.parseArgs=function(e,t,o=s){const r={},i=[],l=[];for(let e in t){if("_"===e[0])continue;const n=t[e];n.alias&&(r[e]=n.alias),"string"===n.type||"string[]"===n.type?(i.push(e),n.deprecates&&i.push(n.deprecates)):"boolean"===n.type&&(l.push(e),n.deprecates&&l.push(n.deprecates))}const a=n(e,{string:i,boolean:l,alias:r}),c={};c._=a._.filter(e=>e.length>0),delete a._;for(let e in t){const n=t[e];n.alias&&delete a[n.alias];let r=a[e];n.deprecates&&a.hasOwnProperty(n.deprecates)&&(r||(r=a[n.deprecates]),delete a[n.deprecates]),void 0!==r&&("string[]"===n.type?r&&!Array.isArray(r)&&(r=[r]):"string"===n.type&&Array.isArray(r)&&(r=r.pop(),o.onMultipleValues(e,r)),c[e]=r),delete a[e]}for(let e in a)o.onUnknownOption(e);return c},t.formatOptions=a,t.buildHelpMessage=function(e,t,n,s,l=!0){const c=process.stdout.isTTY&&process.stdout.columns||80;let d=[`${e} ${n}`];d.push(""),
d.push(`${r.localize(33,null)}: ${t} [${r.localize(34,null)}][${r.localize(35,null)}...]`),d.push(""),l&&("win32"===o.platform()?d.push(r.localize(36,null,t)):d.push(r.localize(37,null,t)),d.push(""));const p={};for(const e in s){const t=s[e];if(t.description&&t.cat){let n=p[t.cat];n||(p[t.cat]=n={}),n[e]=t}}for(let e in p){const t=e;let n=p[t];n&&(d.push(i[t]),d.push(...a(n,c)),d.push(""))}return d.join("\n")},t.buildVersionMessage=function(e,t){return`${e||r.localize(38,null)}\n${t||r.localize(39,null)}\n${process.arch}`}})),define(e[16],t([0,1,4,17,8,18,2,12,11,10]),(function(e,t,n,o,r,i,s,l,a,c){"use strict";Object.defineProperty(t,"__esModule",{value:!0});const d=e=>{switch(e){case"user-data-dir":case"extensions-dir":case"list-extensions":case"install-extension":case"uninstall-extension":case"show-versions":case"export-default-configuration":case"install-source":case"driver":return!1;default:return!0}},p=e=>{switch(e){case"version":case"help":case"folder-uri":case"file-uri":case"diff":case"wait":
case"goto":case"reuse-window":case"new-window":case"status":return!0;default:return!1}},f=process.env.VSCODE_IPC_HOOK_CLI,u=process.env.VSCODE_CLIENT_COMMAND,g=process.env.VSCODE_CLIENT_COMMAND_CWD,h=process.env.VSCODE_CLI_AUTHORITY;function m(e,t){if(!f&&!u)return void console.log("Command is only available in WSL or inside a Visual Studio Code terminal.");const o=Object.assign({},l.OPTIONS),i=u?d:p;for(const e in l.OPTIONS){const t=e;i(t)||delete o[t]}f&&(o.gitCredential={type:"string"});const m={onMultipleValues:(e,t)=>{console.error(`Option ${e} can only be defined once. Using value ${t}.`)},onUnknownOption:t=>{console.error(`Ignoring option ${t}: not supported for ${e.executableName}.`)}},v=l.parseArgs(t,o,m),w=h?A:e=>e;if(v.help)return void console.log(l.buildHelpMessage(e.productName,e.executableName,e.version,o,!0));if(v.version)return void console.log(l.buildVersionMessage(e.version,e.commit));if(v.gitCredential)return void function(e){const t={get:"fill",store:"approve",erase:"reject"}[e]
;if(void 0===t)return void console.log("Expected get, store or erase.");let n="";process.stdin.setEncoding("utf8"),process.stdin.on("data",e=>{"\n"!==(n+=e)&&-1===n.indexOf("\n\n",n.length-2)||(process.stdin.pause(),b(t,n).catch(console.error))}),process.stdin.on("end",()=>{b(t,n).catch(console.error)})}(v.gitCredential);let O=(v["folder-uri"]||[]).map(w);v["folder-uri"]=O;let z=(v["file-uri"]||[]).map(w);v["file-uri"]=z;let P=v._,k=!1;for(let e of P)"-"===e?k=!0:x(e,w,O,z);if(delete v._,k&&0===z.length&&0===O.length&&c.hasStdinWithoutTty()){const e=c.getStdinFilePath();try{c.readFromStdin(e,!!v.verbose),x(e,w,O,z),v.wait=!0,v["skip-add-to-recently-opened"]=!0,console.log(`Reading from stdin via: ${e}`)}catch(e){console.log(`Failed to create file to read via stdin: ${e.toString()}`)}}if(v.extensionDevelopmentPath&&(v.extensionDevelopmentPath=v.extensionDevelopmentPath.map(e=>w(C(e).href))),v.extensionTestsPath&&(v.extensionTestsPath=w(C(v.extensionTestsPath).href)),h&&(v.remote=h),u){let e=[];for(let t in v){
let n=v[t];if("boolean"==typeof n)n&&e.push("--"+t);else if(Array.isArray(n))for(let o of n)e.push(`--${t}=${o.toString()}`);else n&&e.push(`--${t}=${n.toString()}`)}const t=s.extname(u);if(".bat"===t||".cmd"===t){const t=g||process.cwd();v.verbose&&console.log(`Invoking: cmd.exe /C ${u} ${e.join(" ")} in ${t}`),r.spawn("cmd.exe",["/C",u,...e],{stdio:"inherit",cwd:t})}else{const t=s.dirname(u),n=Object.assign(Object.assign({},process.env),{ELECTRON_RUN_AS_NODE:"1"});e.unshift("resources/app/out/cli.js"),v.verbose&&console.log(`Invoking: ${u} ${e.join(" ")} in ${t}`),r.spawn(u,e,{cwd:t,env:n,stdio:["inherit"]})}}else{if(0===t.length)return void console.log(l.buildHelpMessage(e.productName,e.executableName,e.version,o,!0));if(v.status)return void y({type:"status"}).then(e=>{console.log(e)});if(!z.length&&!O.length)return void console.log("At least one file or folder must be provided.");let r=void 0;if(v.wait){if(!z.length)return void console.log("At least one file must be provided to wait for.")
;r=a.createWaitMarkerFile(v.verbose)}y({type:"open",fileURIs:z,folderURIs:O,diffMode:v.diff,addMode:v.add,gotoLineMode:v.goto,forceReuseWindow:v["reuse-window"],forceNewWindow:v["new-window"],waitMarkerFilePath:r}),r&&async function(e){for(;n.existsSync(e);)await new Promise(e=>setTimeout(e,1e3))}(r)}}async function b(e,t){const n=await y({type:"command",command:"git.credential",args:[{command:e,stdin:t}]}),{stdout:o,stderr:r,code:i}=JSON.parse(n);o&&process.stdout.write(o),r&&process.stderr.write(r),i&&process.exit(i)}function y(e){return new Promise(t=>{const n=JSON.stringify(e);if(!f)return console.log("Message "+n),void t("");const o={socketPath:f,path:"/",method:"POST"},r=i.request(o,e=>{const n=[];e.setEncoding("utf8"),e.on("data",e=>{n.push(e)}),e.on("error",()=>v("Error in response")),e.on("end",()=>{t(n.join(""))})});r.on("error",()=>v("Error in request")),r.write(n),r.end()})}function v(e){console.error("Unable to connect to VS Code server."),console.error(e),process.exit(1)}t.main=m
;const w=process.env.PWD||process.cwd();function C(e){return e=e.trim(),e=s.resolve(w,e),new o.URL("file:///"+e)}function x(e,t,o,r){let i=t(C(e).href);try{n.lstatSync(n.realpathSync(e)).isFile()?r.push(i):o.push(i)}catch(t){"ENOENT"===t.code?r.push(i):console.log(`Problem accessing file ${e}. Ignoring file`,t)}}function A(e){return e.replace(/^file:\/\//,"vscode-remote://"+h)}let[,,O,z,P,k,..._]=process.argv;m({productName:O,version:z,commit:P,executableName:k},_)}))}).call(this);
//# sourceMappingURL=https://ticino.blob.core.windows.net/sourcemaps/fe22a9645b44368865c0ba92e2fb881ff1afce94/core/vs/server/remoteCli.js.map
