#lang racket

(require 2htdp/universe)
(require "conway-graphics.rkt")
(require "conway.rkt")

(provide conway-start)

(define (conway-draw-handler w)
  (conway-draw (cdr w))
)

(define (conway-click-handler w x y me)
  (cond
    [(mouse=? "button-up" me)
     (cons (car w) (conway-toggle (cdr w)
                                  (quotient y SQUARE_SIZE)
                                  (quotient x SQUARE_SIZE)))]
    [else w])
)

(define (conway-tick-handler w)
  (cond
    [(car w) (cons (car w) (conway-evolve (cdr w)))]
    [else w]))

(define (conway-keyboard-handler w a-key)
  (define board (cdr w))
  (cond
    [(key=? a-key " ") (cons (not (car w)) board)]
    [(key=? a-key "r") (cons (car w) (conway-create-random (conway-rows board) (conway-cols board)))]
    [else w])
)

(define (conway-start rows cols fHz)
  (big-bang (cons #f (conway-create rows cols))
            (on-mouse conway-click-handler)
            (to-draw conway-draw-handler)
            (on-tick conway-tick-handler fHz)
            (on-key conway-keyboard-handler))
)