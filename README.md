# windows-semaphore

Expose the Windows CreateSemaphore API to Node.JS.

## Installation

`windows-semaphore` will only compile in Windows machines, so it is advisable
to use the `--save-optional` flag and wrap the
`require('windows-semaphore')` call in a `try {} catch {}` block, in case your
code also runs on other platforms.

```
npm install --save-optional windows-semaphore
```

## Usage

```javascript
import { Semaphore } from "windows-semaphore";

var semaphore = new Semaphore("my-semaphore");
console.log(semaphore.isActive());
semaphore.release();
```
