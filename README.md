# A Kernel Seedling
This repositroy contains program that shows the current number of running processes or tasks running.

## Building
```shell
make
```

## Running
```shell
sudo insmod proc_count.ko
```
After running, the number of running processes or tasks will be shown.

## Cleaning Up
```shell
make clean
```

## Testing
```python
python -m unittest
```
After running the tests, the output will display the number of tests passed and failed. There are 3 tests in total, and OK indicates passing all three test.

Report which kernel release version you tested your module on
(hint: use `uname`, check for options with `man uname`).
It should match release numbers as seen on https://www.kernel.org/.

```shell
uname -r -s -v
```
Linux 5.14.8-arch1-1 #1 SMP PREEMPT Sun, 26 Sep 2021 19:36:15 +0000