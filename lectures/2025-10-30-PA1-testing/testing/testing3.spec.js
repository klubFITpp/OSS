import { expect } from "vitest"

const userModel = {
  find: (data, connection) => {
    connection.onRequest(data)

    return connection.alwaysReturn
  }
}


// begin actual app code

function attemptLogin(username, password, databaseConnection) {
  const user = userModel.find({ username }, databaseConnection)
  if (!user)
    return false
  if (user.accountDisabled)
    return false
  if (password !== user.password)
    return false

  return true
}

describe('Module 2', () => {
  // Funkce ktera zaznamenava s cim jsme ji volali
  const requestFn = vi.fn()
  const mockConnection = {
    alwaysReturn: {
      username: 'bob',
      password: 'password123',
      accountDisabled: false
    },
    onRequest: requestFn
  }

  it('should login as bob', () => {
    const loginSuccess = attemptLogin('bob', 'password123', mockConnection)
    expect(loginSuccess).toBeTruthy()
  })

  it('should not login as bob', () => {
    expect(attemptLogin('bob', 'password1', mockConnection)).toBeFalsy()
  })

  it('test1', () => {
    const fn = vi.fn()

    fn(1, 2, 3)
    fn(1)
    fn(true)


    expect(fn).toHaveBeenCalled()
    expect(fn).toHaveBeenCalledTimes(3)
    expect(fn).toHaveBeenCalledWith(1, 2, 3)
  })

  it('should do a request with only username', () => {
    requestFn.mockReset()
    expect(requestFn).not.toHaveBeenCalled()

    expect(attemptLogin('bob', 'password123', mockConnection)).toBeTruthy()

    expect(requestFn).toHaveBeenCalled()
    expect(requestFn).toHaveBeenCalledWith({ username: 'bob' })
    expect(requestFn).not.toHaveBeenCalledWith({ username: 'bob2' })

    expect(attemptLogin('bob2', 'password123', mockConnection)).toBeTruthy()
    expect(requestFn).toHaveBeenCalledWith({ username: 'bob' })
  })

})
