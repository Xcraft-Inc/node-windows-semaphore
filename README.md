# node-windows-semaphore

Expose the Windows CreateSemaphore API to Node.JS.

## Installation

`node-windows-semaphore` will only compile in Windows machines, so it is advisable
to use the `--save-optional` flag and wrap the
`require('node-windows-semaphore')` call in a `try {} catch {}` block, in case your
code also runs on other platforms.

```
npm install --save-optional node-windows-semaphore
```

## Usage

```javascript
const { Semaphore } require("node-windows-semaphore");

var semaphore = new Semaphore("my-semaphore");
semaphore.release();
```
