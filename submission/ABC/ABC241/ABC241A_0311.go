// ABC241A
package main

import ("fmt";"os")

func main() {
	// var n int
	// fmt.Fscan(os.Stdin,&n)
	a := make([]int, 10)
	for i := 0; i < 10; i++{
		fmt.Fscan(os.Stdin,&a[i])
	}
    fmt.Println(a[a[a[0]]])
	
}
