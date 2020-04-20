package main

import (
	"os"
	"testing"
)

func Benchmark_First(b *testing.B) {
	f, _ := os.Open("5000.txt")
	b.StartTimer()
	solve(f)
	b.StopTimer()
}
