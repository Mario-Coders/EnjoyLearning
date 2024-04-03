## Conditional probability

The first concept to understand is conditional probability.

You may already be familiar with probability in general. It lets you reason about **uncertain events** with the precision and rigour of mathematics.

Conditional probability is the bridge that lets you talk about **how multiple uncertain events are related**. 
It lets you talk about how the probability of an event can vary under different conditions.

>For example, consider the probability of winning a race, given the condition you didn't sleep the night before. You might expect this probability to be lower than the probability you'd win if you'd had a full night's sleep.

>Or, consider the probability that a suspect committed a crime, given that their fingerprints are found at the scene. You'd expect the probability they are guilty to be greater, compared with had their fingerprints not been found.

## P(A|B)

Which is read as "the probability of event A occurring, given event B occurs".

An important thing to remember is that conditional probabilities are **not the same as their inverses**.
That is, the "probability of event A given event B" is not the same thing as the "probability of event B, given event A".

To remember this, take the following example:
>The probability of clouds, given it is raining (100%) is not the same 
as the probability it is raining, given there are clouds.

## Bayes' Rule in detail

Bayes' Rule tells you how to calculate a conditional probability with information you already have.

It is helpful to think in terms of two events – **a hypothesis** (which can be true or false) and **evidence** (which can be present or absent).

$$ P(Hypothesis|Evidence) = P(Hypothesis) \times \frac{P(Evidence|Hypothesis)}{P(Evidence)} $$

## Ref

[Bayes' Rule – Explained For Beginners](https://www.freecodecamp.org/news/bayes-rule-explained/)