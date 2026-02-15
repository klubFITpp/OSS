
/**
 * Returns the reminder after dividing by two (always positive)
 */
export function rem2(number) {
  if (number < 0)
    return -number % 2;
  return number % 2;
}


describe('mod2 function', () => {

  it('should return base numbers', () => {
    expect(rem2(0)).toStrictEqual(0)
    expect(rem2(1)).toStrictEqual(1)
  })

  it('should modularize positive numbers', () => {
    expect(rem2(2)).toStrictEqual(0)
    expect(rem2(3)).toStrictEqual(1)
    expect(rem2(4)).toStrictEqual(0)
    expect(rem2(5)).toStrictEqual(1)
    expect(rem2(100)).toStrictEqual(0)
    expect(rem2(101)).toStrictEqual(1)
  })

  it('should modularize negative numbers', () => {
    expect(rem2(-1)).toStrictEqual(1)
    expect(rem2(-2)).toStrictEqual(0)
    expect(rem2(-8)).toStrictEqual(0)
    expect(rem2(-9)).toStrictEqual(1)
  })

  it('should cover my specific usecase', () => {
    expect(rem2(Number.MAX_VALUE)).toStrictEqual(0)
  })

})
