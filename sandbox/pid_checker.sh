#!/bin/bash
# https://www.tohoho-web.com/ex/shell.html
# $! 最後に実行したバックグランドプロセスのプロセスID
# :& 直前の置換を繰り返す

pid=0
for i in {1..100000}; do
  : &
  if [ $! -lt $pid ]; then
    echo "Min pid: $!"
    echo "Max pid: $pid"
    break
  fi
  pid=$!
done
