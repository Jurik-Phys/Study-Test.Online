import style from './AboutUsPage.module.css'
import { useNavigate } from "react-router-dom"

const AboutUsPage = () => {
  const navigate = useNavigate();

  return (
      <div className={style.bodyStyle}>
        <div className={style.hText}>About Us</div>
        <div className={style.text}>
          Ivanovo Power Engineering Institute was founded on the basis of Ivanovo-Voznesensk Polytechnic Institute in 1930. In 1938 by the decree of the USSR Supreme Soviet Presidium IPEI was named after V. I. Lenin. In 1992 it was conferred a status of university
        </div>
        <div className={style.placeButton}>
          <button className={style.flatButton} onClick={ ()=>navigate('/')} >Back to Home</button>
        </div>
      </div>
  );
}

export default AboutUsPage;
