/*	channels.go
	Paul Talaga
	Nov 18, 2020
	Example of using Go channels to manage multiple gothreads.
*/

package main

import (
	"fmt"
	"time"
)

func readword(t chan string) {

	var word string
	for {
		fmt.Println("Type a word, then hit Enter.")
		fmt.Scanf("%s", &word)
		t <- word
	}
}

func timer(t chan string) {
	for {
		word := time.Now().Format(time.RFC3339)
		t <- word
		time.Sleep(5 * time.Second)
	}
}

func printstuff(t chan string, prefix string) {
	for {
		word := <-t
		fmt.Println("Got ", prefix, " of ", word)
		time.Sleep(10 * time.Second)
	}
}

func main() {
	messages := make(chan string, 5)

	go readword(messages)
	go timer(messages)
	go printstuff(messages, "First")
	go printstuff(messages, "Second       ")

	time.Sleep(100 * time.Second)
}
