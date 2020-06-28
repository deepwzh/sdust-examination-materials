import React from 'react';
import PropTypes from 'prop-types';
import { withStyles } from '@material-ui/core/styles';
import Card from '@material-ui/core/Card';
import CardActions from '@material-ui/core/CardActions';
import CardContent from '@material-ui/core/CardContent';
import Button from '@material-ui/core/Button';
import Typography from '@material-ui/core/Typography';

import CircularProgress from '@material-ui/core/CircularProgress';


function CircularIndeterminate(props) {
  const { classes } = props;
  return (
    <div style={styles.process_card}>
      {/* <CircularProgress  /> */}
      <div style={styles.progress_container}>
        <div style={styles.percent_div}>{props.percent}%</div>
        <CircularProgress  color="secondary" variant="static" value={props.percent} size={80}></CircularProgress>
      </div>
      
    </div>
  );
}

CircularIndeterminate.propTypes = {
  classes: PropTypes.object.isRequired,
};
const styles = {
  process_card: {
    width: '250px',
  },
  progress_container: {
    width: '200px',
    position: 'relative',
    textAlign: 'center'
  },
  percent_div: {
    zIndex: 0,
    position: 'absolute',
    /* margin: auto; */
    left: '42%',
    top: '38%',
    color: 'black',
  },
  card: {
    minWidth: 275,
  },
  bullet: {
    display: 'inline-block',
    margin: '0 2px',
    transform: 'scale(0.8)',
  },
  title: {
    fontSize: 14,
  },
  pos: {
    marginBottom: 12,
  },
};

function SimpleCard(props) {
  const { classes } = props;
  const bull = <span className={classes.bullet}>•</span>;

  return (
    <Card className={classes.card}>
      <CardContent>
        <Typography className={classes.title} color="textSecondary" gutterBottom>
          Word of the Day
        </Typography>
        <CircularIndeterminate percent={props.percent}/>
      </CardContent>
      <CardActions>
        <Button size="small">Learn More</Button>
      </CardActions>
    </Card>
  );
}

SimpleCard.propTypes = {
  classes: PropTypes.object.isRequired,
};

export default withStyles(styles)(SimpleCard);