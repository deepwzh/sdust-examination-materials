import React, { Component } from 'react';
import BurgerMenu from 'react-burger-menu';
import classNames from 'classnames';
import { BrowserRouter as Router, Route, Link } from "react-router-dom";
import Paper from '@material-ui/core/Paper';
import { withStyles } from '@material-ui/core/styles';
import Card from '@material-ui/core/Card';
import CardHeader from '@material-ui/core/CardHeader';
import CardActions from '@material-ui/core/CardActions';
import CardContent from '@material-ui/core/CardContent';
import Typography from '@material-ui/core/Typography';
import FormGroup from '@material-ui/core/FormGroup';
import FormControlLabel from '@material-ui/core/FormControlLabel';
import Checkbox from '@material-ui/core/Checkbox';
import TextField from '@material-ui/core/TextField';
import Button from '@material-ui/core/Button';
import G6 from '@antv/g6';
import Hierarchy from '@antv/hierarchy';
import PercentCard from './PercentCard';
import './example.css';
import get_tree_graph from './utils';
import './normalize.css';
class MenuWrap extends Component {
  constructor (props) {
    super(props);
    this.state = {

      hidden: false
    };
  }

  componentWillReceiveProps(nextProps) {
    const sideChanged = this.props.children.props.right !== nextProps.children.props.right;

    if (sideChanged) {
      this.setState({hidden : true});

      setTimeout(() => {
        this.show();
      }, this.props.wait);
    }
  }

  show() {
    this.setState({hidden : false});
  }

  render() {
    let style;

    if (this.state.hidden) {
      style = {display: 'none'};
    }

    return (
      <div style={style} className={this.props.side}>
        {this.props.children}
      </div>
    );
  }
}

export default class Demo extends Component {
  constructor (props) {
    super(props);
    this.state = {
      currentMenu: 'scaleRotate',
      side: 'left',
    };
  }





  getItems() {
    let items;

    switch (this.props.menus[this.state.currentMenu].items) {
      case 1:
        items = [
          <a key="0" href=""><i className="fa fa-fw fa-star-o" /><span>Favorites</span></a>,
          <a key="1" href=""><i className="fa fa-fw fa-bell-o" /><span>Alerts</span></a>,
          <a key="2" href=""><i className="fa fa-fw fa-envelope-o" /><span>Messages</span></a>,
          <a key="3" href=""><i className="fa fa-fw fa-comment-o" /><span>Comments</span></a>,
          <a key="4" href=""><i className="fa fa-fw fa-bar-chart-o" /><span>Analytics</span></a>,
          <a key="5" href=""><i className="fa fa-fw fa-newspaper-o" /><span>Reading List</span></a>
        ];
        break;
      case 2:
        items = [
          <h2 key="0"><i className="fa fa-fw fa-inbox fa-2x" /><span>Sidebar</span></h2>,
          <Link to={'/decision-tree'}><i className="fa fa-fw fa-database" /><span>决策树算法</span></Link>,
          <a key="2" href=""><i className="fa fa-fw fa-map-marker" /><span>Location</span></a>,
          <a key="3" href=""><i className="fa fa-fw fa-mortar-board" /><span>Study</span></a>,
          <a key="4" href=""><i className="fa fa-fw fa-picture-o" /><span>Collections</span></a>,
          <a key="5" href=""><i className="fa fa-fw fa-money" /><span>Credits</span></a>
        ];
        break;
      default:
        items = [
          <a key="0" href=""><i className="fa fa-fw fa-star-o" /><span>Favorites</span></a>,
          <a key="1" href=""><i className="fa fa-fw fa-bell-o" /><span>Alerts</span></a>,
          <a key="2" href=""><i className="fa fa-fw fa-envelope-o" /><span>Messages</span></a>,
          <a key="3" href=""><i className="fa fa-fw fa-comment-o" /><span>Comments</span></a>,
          <a key="4" href=""><i className="fa fa-fw fa-bar-chart-o" /><span>Analytics</span></a>,
          <a key="5" href=""><i className="fa fa-fw fa-newspaper-o" /><span>Reading List</span></a>
        ];
    }

    return items;
  }

  getMenu() {
    const Menu = BurgerMenu[this.state.currentMenu];
    const items = this.getItems();
    let jsx;

    if (this.state.side === 'right') {
      jsx = (
        <MenuWrap wait={20} side={this.state.side}>
          <Menu id={this.state.currentMenu} pageWrapId={'page-wrap'} outerContainerId={'outer-container'} right>
            {items}
          </Menu>
        </MenuWrap>
      );
    } else {
      jsx = (
        <MenuWrap wait={20}>
          <Menu id={this.state.currentMenu} pageWrapId={'page-wrap'} outerContainerId={'outer-container'}>
            {items}
          </Menu>
        </MenuWrap>
      );
    }

    return jsx;
  }

  render() {


    return (
      <Router>
        <div id="outer-container" style={{height: '100%'}}>
          {this.getMenu()}
          <main id="page-wrap" >
          <switch>
            <Route exact path="/" component={Home} />
            <Route path="/about" component={About} />
            <Route path="/decision-tree" component={DecisionTree} />
            <Route path="/topics" component={Topics} />
          </switch>
          
          </main>
        </div>
      </Router>
    );
  }
}
const styles = theme => ({
  container: {
    display: 'flex',
    flexWrap: 'wrap',
  },
  textField: {
    // marginLeft: theme.spacing.unit,
    // marginRight: theme.spacing.unit,
  },
  dense: {
    marginTop: 16,
  },
  paperField: {
    padding: '1em',
    margin: '1em'
    // marginLeft: theme.spacing.unit,
    // marginRight: theme.spacing.unit,
  },
  menu: {
    width: 200,
  },
});

class DecisionTree extends React.Component {
  state = {
    checked_id3: false,
    checked_c45: false,
    checked_cart: false,
    id3_data: [],
    form: {
      "data_type": "TEXT",
      "training_data":"",
      "test_data": "",
    },
    "id3_precision": 0,
    "c45_precision": 0,
    "cart_percision": 0,
  }
  handleChange = name => event => {
    this.setState({ [name]: event.target.checked });
  };
  handleClick = () => {
    if (this.state.checked_id3) {
      fetch('/api/algo/id3', {
        method: "POST",
        headers: {
          "content-type": "application/json"
        },
        body: JSON.stringify(this.state.form)
      })
      .then(data => data.json())
      .then(response => {
        this.setState({
          id3_data: response.tree_data,
          id3_precision: (response.precision * 100).toFixed(2)
        })
        const data = response.tree_data.nodes;
        const edges = response.tree_data.edges;
        get_tree_graph('id3_tree_mountNode', data, edges);
        
        // console.log(data);
      });
    } 
    if (this.state.checked_c45) {
      fetch('/api/algo/c45', {
        method: "POST",
        headers: {
          "content-type": "application/json"
        },
        body: JSON.stringify(this.state.form)
      })
      .then(data => data.json())
      .then(response => {
        this.setState({
          c45_data: response.tree_data,
          c45_precision: (response.precision * 100).toFixed(2)
        })
        const data = response.tree_data.nodes;
        const edges = response.tree_data.edges;
        get_tree_graph('c45_tree_mountNode', data, edges);
        // console.log(data);
      });
    }
    if (this.state.checked_cart) {
      fetch('/api/algo/cart', {
        method: "POST",
        headers: {
          "content-type": "application/json"
        },
        body: JSON.stringify(this.state.form)
      })
      .then(data => data.json())
      .then(response => {
        this.setState({
          cart_data: response.tree_data,
          cart_precision: (response.precision * 100).toFixed(2)
        })
        const data = response.tree_data.nodes;
        const edges = response.tree_data.edges;
        get_tree_graph('cart_tree_mountNode', data, edges);
        // console.log(data);
      });
    }
  };
  render() {
    const { classes } = this.props;
    return (
      <div>
        <Card
          className={classes.paperField}>
           <CardContent>
              <Typography gutterBottom variant="h5" component="h5">
                Step1: 数据集导入
              </Typography>
              <form>
              <TextField
                id="filled-multiline-static"
                label="训练数据集"
                multiline
                rows="4"
                value={this.state.form.training_data}
                defaultValue="Default Value"
                fullWidth
                onChange={ (e) => this.setState({
                  form: {
                    ...this.state.form,
                    training_data: e.target.value, 
                  }
                })}
                className={classes.textField}
                margin="normal"
                variant="filled"
              />
              <TextField
                id="filled-multiline-static"
                label="测试数据集"
                multiline
                rows="4"
                fullWidth
                defaultValue="Default Value"
                value={this.state.form.test_data}
                onChange={ (e) => this.setState({
                  form: {
                    ...this.state.form,
                    test_data: e.target.value, 
                  }
                })}
                className={classes.textField}
                margin="normal"
                variant="filled"
              />
              </form>

           </CardContent>
        </Card>
        <Card className={classes.paperField}>
          <CardContent>
            <Typography gutterBottom variant="h5" component="h5">
                Step2:选择决策树算法
            </Typography>
            <FormGroup row>
              <FormControlLabel
                control={
                  <Checkbox
                    checked={this.state.checked_id3}
                    onChange={this.handleChange('checked_id3')}
                    value="checked_id3"
                    color="primary"

                  />
                }
                label="ID3"
              />
              <FormControlLabel
                control={
                  <Checkbox
                    checked={this.state.checked_c45}
                    onChange={this.handleChange('checked_c45')}
                    value="checked_c45"
                    color="primary"
                  />
                }
                label="C4.5"
              />
              <FormControlLabel
                control={
                  <Checkbox
                    checked={this.state.checked_cart}
                    onChange={this.handleChange('checked_cart')}
                    value="checked_cart"
                    color="primary"
                  />
                }
                label="CART"
              />
            </FormGroup>
            <Button variant="contained" color="primary" className={classes.button} onClick={this.handleClick}>
              执行算法
            </Button>
          </CardContent>
        </Card>
        <Card
          className={classes.paperField}>
           <CardContent>
              <Typography gutterBottom variant="h5" component="h5">
                ID3算法
              </Typography>
              <PercentCard percent={this.state.id3_precision} />
              <div id="id3_tree_mountNode"></div>
            </CardContent>
        </Card>
        <Card
          className={classes.paperField}>
           <CardContent>
              <Typography gutterBottom variant="h5" component="h5">
                C4.5算法
              </Typography>
              <PercentCard percent={this.state.c45_precision} />
              <div id="c45_tree_mountNode"></div>
            </CardContent>
        </Card>
        <Card
          className={classes.paperField}>
           <CardContent>
              <Typography gutterBottom variant="h5" component="h5">
                CART算法
              </Typography>
              <PercentCard percent={this.state.cart_precision} />
              <div id="cart_tree_mountNode"></div>
            </CardContent>
        </Card>
      </div>
    );
  }
}
DecisionTree = withStyles(styles)(DecisionTree);
function Home() {
  return (
    <div>
      <h2>Home</h2>
    </div>
  );
}

function About() {
  return (
    <div>
      <h2>About</h2>
    </div>
  );
}

class Topics extends React.Component {
  state = {
    currentMenu: 'slide',
    side: 'left'
  }
  changeMenu = (menu) => {
    this.setState({currentMenu: menu});
  }
  changeSide = (side) => {
    this.setState({side});
  }
  menus = {
    slide: {buttonText: 'Slide', items: 1},
    stack: {buttonText: 'Stack', items: 1},
    elastic: {buttonText: 'Elastic', items: 1},
    bubble: {buttonText: 'Bubble', items: 1},
    push: {buttonText: 'Push', items: 1},
    pushRotate: {buttonText: 'Push Rotate', items: 2},
    scaleDown: {buttonText: 'Scale Down', items: 2},
    scaleRotate: {buttonText: 'Scale Rotate', items: 2},
    fallDown: {buttonText: 'Fall Down', items: 2},
    reveal: {buttonText: 'Reveal', items: 1}
  }
  buttons = Object.keys(this.menus).map((menu) => {
    return (
      <a key={menu}
        className={classNames({'current-demo': menu === this.state.currentMenu})}
        onClick={() => this.changeMenu(menu)}>
        {this.menus[menu].buttonText}
      </a>
    );
  });
  render() {
    return (
      <div>
        <h1><a href="https://github.com/negomi/react-burger-menu">react-burger-menu</a></h1>
        <a className={classNames({'side-button': true, 'left': true, 'active': this.state.side === 'left'})} onClick={() => this.changeSide('left')}>Left</a>
        <a className={classNames({'side-button': true, 'right': true, 'active': this.state.side === 'right'})} onClick={() => this.changeSide('right')}>Right</a>
        <h2 className="description">An off-canvas sidebar React component with a collection of effects and styles using CSS transitions and SVG path animations.</h2>
        <nav className="demo-buttons">
          {this.buttons}
        </nav>
      </div>
    );
  }
}

Demo.defaultProps = {
  menus: {
    slide: {buttonText: 'Slide', items: 1},
    stack: {buttonText: 'Stack', items: 1},
    elastic: {buttonText: 'Elastic', items: 1},
    bubble: {buttonText: 'Bubble', items: 1},
    push: {buttonText: 'Push', items: 1},
    pushRotate: {buttonText: 'Push Rotate', items: 2},
    scaleDown: {buttonText: 'Scale Down', items: 2},
    scaleRotate: {buttonText: 'Scale Rotate', items: 2},
    fallDown: {buttonText: 'Fall Down', items: 2},
    reveal: {buttonText: 'Reveal', items: 1}
  }
}