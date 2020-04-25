package main

import (
	"fmt"
	"math/rand"
	"os"
	"strconv"
	"time"
)

func main() {

	if len(os.Args) < 3 {
		fmt.Println("Missing arguments.")
		os.Exit(1)
	}

	rand.Seed(time.Now().UnixNano())

	f, err := os.Create(os.Args[1])
	defer f.Close()

	if err != nil {
		fmt.Printf("Unable to create file: %v\n", err)
	}

	var n, w int64
	n, err = strconv.ParseInt(os.Args[2], 10, 64)

	if err != nil {
		fmt.Printf("Unable to parse argument as a number: %v\n", err)
	}

	if len(os.Args) >= 4 {
		w, err = strconv.ParseInt(os.Args[3], 10, 64)

		if err != nil {
			fmt.Printf("Unable to parse argument as a number: %v\n", err)
		}
	} else {
		w = n * int64(rand.Intn((10-2))+2)
	}

	fmt.Fprintf(f, "%v\n", n)

	var max int64

	max = int64(1.5 * float64(w))
	for i := int64(1); i < n; i++ {
		fmt.Fprintf(f, "%v ", rand.Int63n(int64(max))+1)
	}
	fmt.Fprintf(f, "%v\n", rand.Int63n(int64(max))+1)

	max = int64(2.5 * float64(w))
	for i := int64(1); i < n; i++ {
		fmt.Fprintf(f, "%v ", rand.Int63n(int64(max))+1)
	}
	fmt.Fprintf(f, "%v\n", rand.Int63n(int64(max))+1)

	fmt.Fprintf(f, "%v", w)

}
