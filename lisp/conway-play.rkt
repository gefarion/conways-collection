#lang racket

(require "conway-ui.rkt")

(define ROWS 20)
(define COLS 30)
(define TICK 0.1)

(conway-start ROWS COLS TICK)
(void)

