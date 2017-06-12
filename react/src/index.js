import React from 'react';
import ReactDOM from 'react-dom';


class Foo extends React.Component {
  render () {
    return (
      <div> foo </div>
    );
  }
}

ReactDOM.render(
  <Foo/>,
  document.getElementById("root")
);
