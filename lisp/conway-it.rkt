#lang racket

(provide conway-create conway-create-random conway-evolve conway-toggle conway-cols conway-rows)

(define (conway-create rows cols)
  (build-vector rows (λ (x) (make-vector cols 0))))

(define (conway-create-random rows cols)
  (build-vector rows (λ (x) (build-vector cols (λ (x) (random 2))))))

(define (conway-rows board) (vector-length board))

(define (conway-cols board) (vector-length (vector-ref board 0)))

(define (conway-ref board row col)
  (define rows (conway-rows board))
  (define cols (conway-cols board))
  (if (or (< row 0) (< col 0) (>= row rows) (>= col cols))
      0
      (vector-ref (vector-ref board row) col)))

(define (conway-set! board row col v)
  (vector-set! (vector-ref board row) col v))

(define (conway-toggle board row col)
  (define value (conway-ref board row col))
  (conway-set! board row col (if (zero? value) 1 0))
  board)

(define (conway-neighbors board row col)
 (+
   (conway-ref board (sub1 row) (sub1 col))
   (conway-ref board (sub1 row) col)
   (conway-ref board (sub1 row) (add1 col))
   (conway-ref board row (sub1 col))
   (conway-ref board row (add1 col))
   (conway-ref board (add1 row) (sub1 col))
   (conway-ref board (add1 row) col)
   (conway-ref board (add1 row) (add1 col))))

(define (conway-evolve-cell board row col)
  (define neighbors (conway-neighbors board row col))
  (cond [(= 2 neighbors) (conway-ref board row col)]
        [(= 3 neighbors) 1]
        [else 0]))
   
(define (conway-evolve board)
  (define rows (conway-rows board))
  (define cols (conway-cols board))
  (define new-board (conway-create rows cols))
  (for ([row (range rows)])
    (for ([col (range cols)])
      (conway-set! new-board row col (conway-evolve-cell board row col))))
  new-board)