#!/bin/esh
func(){
  if [[ ($operator > 050 && $operator < 089) || ($operator == 482) || ($operator > 150 && $operator < 189)  ]]; then echo "$operator OK"; fi
}
operator=050; func
operator=051; func
operator=153; func
operator=482; func
operator=483; func
