import React from 'react'

function Counter() {
    const [count, setCount] = React.useState(0)

    React.useEffect(() => {
        setTimeout(() => {}, 1000)
    }, [])

    return (
        <div>
            <h1>{count}</h1>
            <button onClick={() => setCount(count + 1)}>Increment</button>
        </div>
    )
}

export default Counter